# Deribit Order Execution and Management System

## Overview

This project is a C++ application designed to interact with the Deribit API for trading. It provides functionalities for authentication, placing orders, modifying orders, viewing current positions, canceling orders, and retrieving order book information.

## Features

- **Authentication**: Securely obtain an access token to interact with the Deribit API.
- **Order Management**: Place, modify, and cancel orders on the Deribit platform.
- **Position Tracking**: View current trading positions and their statuses.
- **Order Book Access**: Retrieve the order book for specific instruments.

## Technologies Used

- C++
- cURL for API HTTP requests
- nlohmann/json for JSON handling
- Deribit API (test environment)

## Demonstration video
https://drive.google.com/file/d/1Xt5hhS_8iCyhh1MBX8bVDMGa0XepT_ZR/view?usp=sharing

## Getting Started

### Prerequisites

- C++ compiler (e.g., GCC or Clang)
- cURL library
- nlohmann/json library

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/shreyp135/Deribit-Trading-system.git
   ```
2. Make sure to install the required libraries (cURL and nlohmann/json).
3. Update the credentials.cpp file with your Deribit API client ID and client secret.
4. Compile and build the project.


## API Endpoints
- Authentication: POST /public/auth 
- Place Order: POST /private/{action}
- Modify Order: POST /private/edit
- View Current Positions: GET /private/get_positions
- Cancel Order: POST /private/cancel
- Get Order Book: GET /public/get_order_book
