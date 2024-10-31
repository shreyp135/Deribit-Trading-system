#include <bits/stdc++.h>
#include "json.hpp"
#include <curl/curl.h>
#include "credentials.cpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using json = nlohmann::json;

extern std::string accessToken;

    //callback for curl
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
}

    // authentication function to get access token
    bool auth() {
        CURL* curl;
        CURLcode res;
        string readBuffer;

        curl = curl_easy_init();
        if (curl) {
            string url = base_url + "/public/auth";
            string postFields = "grant_type=client_credentials&client_id=" + client_id + "&client_secret=" + client_secret;

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.c_str());

            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }

        json res = json::parse(readBuffer);
        if (res.contains("result")) {
            cout << "Authentication successful! Access Token: " << res["result"]["access_token"] << "\n";
            accessToken = res["result"]["access_token"];
            return true;
        } else {
            cout<< "Authentication failed, please try again !!"<< endl;
            return false;
        }
    }

    // Function to place an order
    json placeOrder(string& instrumentName, double amount, double price, string& act) {
        CURL* curl;
        CURLcode res;
        string readBuffer;

        curl = curl_easy_init();
        if (curl) {
            string url = base_url + "/private/" + act;
            string postFields = "instrument_name=" + instrumentName + "&amount=" + to_string(amount) + "&price=" + to_string(price) + "&access_token=" + accessToken;

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.c_str());

            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }

        return json::parse(readBuffer);
    }

    // Function to modify an order
    json modifyOrder( string& orderId, double newAmount, double newPrice) {
        CURL* curl;
        CURLcode res;
        string readBuffer;

        curl = curl_easy_init();
        if (curl) {
            string url = base_url + "/private/edit";
            string postFields = "order_id=" + orderId + "&amount=" + to_string(newAmount) + "&price=" + to_string(newPrice) + "&access_token=" + accessToken;

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.c_str());

            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }

        return json::parse(readBuffer);
    }

    // Function to view current positions
    json viewCurrentPositions() {
        CURL* curl;
        CURLcode res;
        string readBuffer;

        curl = curl_easy_init();
        if (curl) {
            string url = base_url + "/private/get_positions?access_token=" + accessToken;

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }

        return json::parse(readBuffer);
    }

    // Function to cancel an order
    json cancelOrder( string& orderId) {
        CURL* curl;
        CURLcode res;
        string readBuffer;

        curl = curl_easy_init();
        if (curl) {
            string url = base_url + "/private/cancel";
            string postFields = "order_id=" + orderId + "&access_token=" + accessToken;

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.c_str());

            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }

        return json::parse(readBuffer);
    }

    // Function to get the order book for an instrument
    json getOrderBook( string& instrument) {
        CURL* curl;
        CURLcode res;
        string readBuffer;

        curl = curl_easy_init();
        if (curl) {
            string url = base_url + "/public/get_order_book?instrument_name=" + instrument;

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }

        return json::parse(readBuffer);
    }


