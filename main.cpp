//Isaac Perez a restaurant structure style
//Dr_T programmng fundaments 2
//using structures and vectors to create a restaraunt menu
#include <iostream>
#include<string>
#include<vector>
#include<iomanip>//for set percision
#include <unistd.h>//for pause command
#include<fstream>// out put to text file
using namespace std;

struct MenuItem
{
  string name;
  double itemCost;
  string desc;
  char addLetter;
  char removeLetter;
  int count; //how many of that item did you order
};

//function definition
void populateMenu(vector<MenuItem> &entireMenu)
{
//put some default values in our Menu
const int numitems = 7;
MenuItem item1;// Item1 is data type MenuItem
MenuItem item2;
MenuItem item3;
MenuItem item4;
MenuItem item5;
MenuItem item6;
MenuItem item7;

entireMenu.push_back(item1);//add to the end of the list the Item1
entireMenu.push_back(item2);//add to the end of the list the Item2
entireMenu.push_back(item3);//add to the end of the list the Item3
entireMenu.push_back(item4);
entireMenu.push_back(item5);
entireMenu.push_back(item6);
entireMenu.push_back(item7);

vector<string> defaultMenuNames = {"Green tea", "Ramen","Gyoza", "jalepenos", "bacon", "Beer", "Fish"};
vector<char> defaultAddLetters = { 'A', 'B','C','D','E','F','G'};
vector<char> defaultRemoveLetters = {'a','b','c','d','e','f','g'};

for(int i = 0; i < numitems; i++)
{
  //add each item to the default list efficiently 
  entireMenu[i].name = defaultMenuNames[i];
  entireMenu[i].addLetter = defaultAddLetters[i];
  entireMenu[i].removeLetter = defaultRemoveLetters[i];
  entireMenu[i].itemCost = (3.00 + i);// sset a random starter cost for each item
  entireMenu[i].count = 0; // initialixe all counts to 0
  entireMenu[i].desc = "delicous"; //set all default desc to "delicious"
}


}

//define the above showMenu, because show menu calls it
void printReceipt(vector<MenuItem> &m, double s)
{
//process for cal total with tax(accept tip)
double tipAmount = 0.0, totalWithTax = 0.0, taxRate = .0825;
double taxAmount = 0.0, totalDue = 0.0, tenderAmount = 0.0, change = 0.0;
int decision =0;
ofstream myfile;
myfile.open("receipt.txt");

string cc = "";
cout <<"\nSubTotal Due: $"<< s << endl;
taxAmount = (s * .0825);
cout << "\nSuggested tip amount (20%): $" << (s * .20)<<endl;
cout << "Tax Amount $" <<taxAmount << endl;
totalWithTax = s + taxAmount;
cout << "total with Tax: " <<(totalWithTax);
//process for calc total with tax (accept tip)
cout <<"\nPlease enter a tip amount: ";

cin>> tipAmount;

totalDue = totalWithTax + tipAmount;
cout << "Total Due $" <<totalDue << endl;

cout << "\nHow would you like to pay(1=cash, 2=card): ";
cin >> decision;

if(decision == 1)//cash
{
  cout << "\nYou have selected to pay cash.";
 
 do
 {
   cout << "\nPlease enter your tender amount: $";
   cin >> tenderAmount;
   if(tenderAmount < totalDue)
   {
     cout << "\nInsufficient funds (try again)" << endl;
   }

   if(tenderAmount > totalDue)
   {
     change = tenderAmount - totalDue;//show me that money!!
     cout << "Your change is $: "<<change<< endl;
   }
 }while(tenderAmount < totalDue);//loop until tender amount >= totaldue
}
else if (decision == 2)//credit card
{
  cout<< "\nYou have selected to pay wiht credit card";
  cout<< "\nPlease enter you credit card number: ";
  cin >> cc;
  //process credit card to do a dram
  sleep(2);
  cout << "Approved!"<<endl;
  cout <<""<<endl;
}
else
{
  cout << "\nInvalid input" << endl;
}

//show the reciept on screen here
cout << "**************RECIEPT - Tandy's Slop Shop***************** " <<endl;
for(int i =0; i < m.size(); i++)
{
  //print on the receipt if coutn > 0
  if(m[i].count > 0)
  {
    cout <<setw(10)<< m[i].name<<" "<<setw(15)<<
    m[i].count << " @$" <<m[i].itemCost<<setw(20) << " $"
    <<(m[i].count * m[i].itemCost)//running total
    << endl;

  }
}
 cout<<"----------------------------------------------------------"<<endl;
cout <<"\nTotal Due: $"<< s << endl;
cout << "Tax Rate " << (taxRate * 100)<<"%" << endl;
cout << "Tax Amount $" <<taxAmount << endl;
cout << "total with Tax: " <<(totalWithTax);
cout <<"\nTip Amount: $:" << tipAmount << endl;
cout << "Total Due $" <<totalDue << endl;

 if(decision == 1) //cash payment
  {
    cout << "Tender Amount $" << tenderAmount << endl; 
    cout << "Change $" << change << endl; 
  }
  else
  {
    cout << "Credit Card Status: APPROVED" << endl; 
  }

  //print a text copy of the same Reciept 

 
  myfile << "**************RECIEPT - Tandy's Slop Shop***************** " <<endl;
for(int i =0; i < m.size(); i++)
{
  //print on the receipt if coutn > 0
  if(m[i].count > 0)
  {
    myfile <<setw(10)<< m[i].name<<" "<<setw(15)<<
    m[i].count << " @$" <<m[i].itemCost<<setw(20) << " $"
    <<(m[i].count * m[i].itemCost)//running total
    << endl;

  }
}
myfile <<"----------------------------------------------------------"<<endl;
myfile <<"\nTotal Due: $"<< s << endl;
myfile<< "Tax Rate " << (taxRate * 100)<<"%" << endl;
myfile << "Tax Amount $" <<taxAmount << endl;
myfile << "total with Tax: " <<(totalWithTax);
myfile <<"\nTip Amount: $:" << tipAmount << endl;
myfile << "Total Due $" <<totalDue << endl;

  myfile.close(); //close the file after printing
}

void showMenu(vector<MenuItem> &m)//do not need to declare size
{
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << "Tandy's Slop Shop" << endl;
  cout << "ADD \tNAME \t COST \tREMOVE\tCOUNT\tDESC" <<endl;//\t is tab
  for(int i = 0; i < m.size(); i++)
  {
    //set w is for cushion
    cout <<m[i].addLetter << ")" << setw(10) << m[i].name
    <<setw(5) <<"$" <<m[i].itemCost <<setw(7)<< "(" << m[i].removeLetter << ")" << setw(7) << m[i].count  << setw(11) << m[i].desc
     <<endl;

  }

}
void tipAmount(double s )

{
double tip = 0.0;
double suggestTipAmount = s * .20;
 cout << "\nWould you like to leave a tip? (20% or more is preferable): " << endl;
 cout << "\nSuggest tip amount: $" <<suggestTipAmount << endl;
}

void acceptOrder(vector<MenuItem> &m)
{
  char option = '\0' ;// the user selected menu item
  double subtotal = 0.0;

  double tax = .825;
  double total = 0.0;

  do
  {
    cout << "\nPlease choose an item  (x to Exit): ";
    cin >> option; 

    for(int i =0; i < m.size(); i ++)
    {
      if(option == m[i].addLetter)
      {
        cout << "\nMenu Item " << m[i].name << " selected.";//addLetter
        m[i].count++;//increment count by 1
        cout << "\033[2J\033[1;1H";//clear screen
        cout << "\n1 UP on " << m[i].name << endl;
        subtotal += m[i].itemCost;//increment the subtotal by the cost of the item
        showMenu(m);
        cout << "\nSubtotal: $" << subtotal << endl;
      }

      else if(option == m[i].removeLetter)
      {
        cout << "\nMenu Item " <<m[i].name << " removed.";
        if(m[i].count > 0)
        {
          m[i].count --;// decrement by 1
           cout << "\033[2J\033[1;1H";//clear screen
           cout << "\n1 DOWN on " << m[i].name << endl;
           subtotal -= m[i].itemCost;//decrement the subtotal by the cost of the item
           showMenu(m);
           cout << "\nSubtotal: $" <<subtotal << endl;

        }
        else 
        {
  
          cout << "\nItem coutn must be > 0 to remove: " <<m[i].name << endl;
        }
      }
      else if (option != m[i].addLetter &&
              option != m[i].removeLetter &&
              option != 'x'&& option != 'X')
              {
                if ( i == 0)
                {
                cout << "\nInvalid input (" << option << "). Please try again." << endl;
                }
              }
         }

  }while(option != 'X' && option != 'x');
  cout << "\nPlease leave." <<endl;
 //handle the tip process here
 //handle reciept generation here
 printReceipt(m,subtotal);
//tipAmount(subtotal);
}



int main() // a vector is an alternative to the one dimensional array.grows dynamically on its own. 
{
  

vector<MenuItem> wholeMenu;// name is wholeMenu
string decision = "";

populateMenu(wholeMenu);
showMenu(wholeMenu);// print the current data of the menu on screen
do
{
acceptOrder(wholeMenu);
cout << "\nWould you like to order again. Type \"exit\", otherwise: ";
cin >> decision;
if(decision != "exit")
{
  cout << "\033[2J\033[1;1H";//clear screen
  cout << "Welcome Back" <<endl;
  //reset
  for(int i =0; i < wholeMenu.size(); i++)
  {
    wholeMenu[i].count = 0;
  }
  showMenu(wholeMenu);
}
}while(decision != "exit");
cout << "Time To Leave";
  return 0;
}