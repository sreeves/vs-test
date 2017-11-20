#include <iostream>
#include <iomanip>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

void GetInfo(ItemToPurchase& item) {
   cin.ignore();
   string itemName;
   double itemPrice = 0.0;
   int itemQuantity = 0;
   string itemDescription;
   string enterName = "Enter the item name: ";
   string enterPrice = "Enter the item price: ";
   string enterQuantity = "Enter the item quantity: ";
   string enterDescription = "Enter the item description: ";
   cout << enterName << endl;
   getline(cin, itemName);
   //item.SetName(itemName);
   cout << enterDescription << endl;
   getline(cin, itemDescription);
   
   cout << enterPrice << endl;
   cin >> itemPrice;
   //item.SetName(itemName);
   //item.SetPrice(itemPrice);
   cout << enterQuantity << endl;
   cin >> itemQuantity;
   //item.SetQuantity(itemQuantity);
   item = ItemToPurchase(itemName, itemDescription, itemPrice, itemQuantity);
   cin.ignore();
   
   cout << endl;
   
   return;
}

void PrintMenu() {
   cout << "MENU" << endl;
   cout << "add - Add item to cart" << endl;
   cout << "remove - Remove item from cart" << endl;
   cout << "change - Change item quantity" << endl;
   cout << "descriptions - Output items' descriptions" << endl;
   cout << "cart - Output shopping cart" << endl;
   cout << "options - Print the options menu" << endl;
   cout << "quit - Quit" << endl;
   return;
}


int main() {
   string userName;
   string userDate;
   bool done = false;
   string userChoice;
   ItemToPurchase newItem;
   string itemName;
   int newQuantity;

   cout << "Enter Customer's Name: " << endl;
   getline(cin, userName);
   cout << "Enter Today's Date: " << endl;
   getline(cin, userDate);
   ShoppingCart myCart = ShoppingCart(userName, userDate);

   do {
      cout << "Enter option: " << endl;
      cin >> userChoice;
      if (userChoice == "options") {
         PrintMenu();
      }
      else if (userChoice == "quit"){
         cout << "Goodbye." << endl;
         done = true;
      }
      else if (userChoice == "add") {
         GetInfo(newItem);
         myCart.AddItem(newItem);
      }
      else if (userChoice == "remove") {
         cout << "Enter name of the item to remove: " << endl;
         cin >> itemName;
         myCart.RemoveItem(itemName);
         cin.ignore(); 
      }
      else if (userChoice == "change") {
         cout << "Enter name of the item name: " << endl;
         cin >> itemName;
         cout << "Enter the new quantity: " << endl;
         cin >> newQuantity;
         myCart.ChangeQuantity(itemName, newQuantity);
         cin.ignore();
      }
      else if (userChoice == "descriptions") {
         cout << myCart.GetName() << "'s Shopping Cart - " << myCart.GetDate() << endl;
         cout << "Item Descriptions" << endl;
         myCart.PrintDescriptions();
      }
      else if (userChoice == "cart") {
         int numItems = 0;
         double totalPrice = 0.0;
         cout << myCart.GetName() << "'s Shopping Cart - " << myCart.GetDate() << endl;
         myCart.NumItemsAndPrice(numItems, totalPrice);
         
      }
      else {
         PrintMenu();
      }



   } while(!done);




   // ItemToPurchase item1;
   // ItemToPurchase item2;
   // int setPrecision = 2;


   // cout << "Item 1" << endl;
   // GetInfo(item1);

   // cout << "Item 2" << endl;
   // GetInfo(item2);
   
   // cout << fixed << setprecision(setPrecision);
   // cout << "TOTAL COST" << endl;
   // cout << item1.GetName() << " " << item1.GetQuantity() << " @  $" << item1.GetPrice() << " = $" << item1.GetQuantity() * item1.GetPrice() << endl;
   // cout << item2.GetName() << " " << item2.GetQuantity() << " @  $" << item2.GetPrice() << " = $" << item2.GetQuantity() * item2.GetPrice() << endl;
   // cout << "Total: $" << (item1.GetQuantity() * item1.GetPrice()) + (item2.GetQuantity() * item2.GetPrice());
   
   return 0;
}