#include "main.hpp"

int main() {
    int choice{};
    bool isAuth{false};
    do {
        cout << "Hello and welcome to deribit trading system, please select from the below options: -" << endl;
        cout << "1. Place an Order" << endl;
        cout << "2. Cancel an Order" << endl;
        cout << "3. Modify an Order" << endl;
        cout << "4. Get Order Book" << endl;
        cout << "5. View Current Positions" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (!isAuth) {
                    if(!auth()){
                        break;
                    };
                }
                string instrument;
                double amount, price;
                string act;
                cout << "Enter instrument name: ";
                cin >> instrument;
                cout << "Enter amount: ";
                cin >> amount;
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter action (buy/sell): ";
                cin >> act;

                json res = placeOrder(instrument, amount, price, act);
                cout << "Order Response: " << res.dump(4) << endl;
                break;
            }
            case 2: {
                 if (!isAuth) {
                    if(!auth()){
                        break;
                    };
                }
                string orderId;
                cout << "Enter Order ID to cancel: ";
                cin >> orderId;

                json res = cancelOrder(orderId);
                cout << "Cancel Order Response: " << res.dump(4) << endl;
                break;
            }
            case 3: {
                 if (!isAuth) {
                    if(!auth()){
                        break;
                    };
                }
                string orderId;
                double newAmount, newPrice;
                cout << "Enter Order ID to modify: ";
                cin >> orderId;
                cout << "Enter new amount: ";
                cin >> newAmount;
                cout << "Enter new price: ";
                cin >> newPrice;

                json res = modifyOrder(orderId, newAmount, newPrice);
                cout << "Modify Order Response: " << res.dump(4) << endl;
                break;
            }
            case 4: {
                if (!isAuth) {
                    if(!auth()){
                        break;
                    };
                }
                string instrument;
                cout << "Enter instrument for order book: ";
                cin >> instrument;

                json res = getOrderBook(instrument);
                cout << "Order Book: " << res.dump(4) << "\n";
                break;
            }
            case 5: {
                if (!isAuth) {
                    if(!auth()){
                        break;
                    };
                }
                json res = viewCurrentPositions();
                cout << "Current Positions: " << res.dump(4) << endl;
                break;
            }
            case 6: {
                cout << "Thanks for using Deribit trading system !!";
                break;
            }
            default:
                cout << "Invalid choice, Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
