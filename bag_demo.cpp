#include<iostream>

#include "bag.cpp"

int main()
{
    Bag<int> bag(10);
    int n;

    for (int i = 0; i < 7; i++)
        bag += i;

    cout << "bag:\n" << bag << endl;

    Bag<int> bagI = bag;
    cout << "bagI:\n" << bagI << endl;

    bag += 9;
    cout << "bagI:\n" << bagI << endl;

    bagI += 2;
    cout << "bag:\n" << bag << endl;

    Bag<int> bagG(10);
    for (int i = 0; i < 6; i++)
        bagG += i;
    cout << "bagG:\n" << bagG << endl;

    bagI = bagG;
    cout << "bagI:\n" << bagI << endl;
    bagG += 14;
    cout << "bagI:\n" << bagI << endl;

    Bag<int> bagK(10);
    for (int i = 19; i < 25; i++)
        bagK += i;

    cout << "bagG:\n" << bagG << endl;
    cout << "bagK:\n" << bagK << endl;
    bag = bagK + bagG;
    cout << "bag:\n" << bag << endl;

    cout << "bagI + 7 :\n" << bagI+7 << endl;

    cout << "bagI + bagG:\n" << bagI + bagG << endl;

    if(bag.isEmpty())
        cout << "Bag is empty\n";
    else
        cout << "Bag is Not empty\n";

    cout << "Enter an int to look up in the bag: ";
    cin >> n;
    if(bag.contains(n)==true)
        cout << "Bag contains " << n << endl;
    else
        cout << "Bag does not contain " << n << endl;

    bag += 3;
    cout << "Enter an int to look up it's occurrence in the Bag: ";
    cin >> n;
    if(bag.find(n) > 0)
        cout << "The int occurrs: " << bag.find(n)  << " times in the bag" << endl;
    else
        cout << "Bag does not contain " << n << endl;

    bag.clear();
    cout << "bag:\n" << bag << endl;

    bag = bagI;
    cout << "bag:\n" << bag << endl;
    
    
    Bag<string> strBag;
	string str;
	strBag += "nike";
	strBag += "adidas";
	strBag += "puma";
	strBag += "armani";
	cout << "strBag:\n" << strBag << endl;
	
	cout << "Enter a string to look up in the bag: ";
	cin >> str;
	if(strBag.contains(str))
	cout << "Bag contains " << str << endl;
	else
	cout << "Bag does not contain " << str << endl; 
	
	cout << "Enter a string to look up it's occurrence in the Bag: ";
	cin >> str;
	if(strBag.find(str) >= 0)
	cout << "The string occurrs: " << strBag.find(str)  << " times in the bag" << endl;
	else
	cout << "Bag does not contain " << str << endl; 
	
	Bag<double> dblBag;
	double d;
	
	for (int i = 0; i < 10; i++)
        dblBag += i + 0.1 ;
	cout << "\ndblBag:\n" << dblBag << endl;
	
	dblBag += 5.1;
	dblBag += 9.7;
	
	Bag<double> dbl2Bag = dblBag;
	cout << "dbl2Bag:\n" << dbl2Bag << endl;
	
	cout << "Enter a double to look up in the bag: ";
	cin >> d;
	if(dblBag.contains(d))
	cout << "Bag contains " << d << endl;
	else
	cout << "Bag does not contain " << d << endl; 
	
	cout << "Enter a double to look up it's occurrence in the Bag: ";
	cin >> d;
	if(dblBag.find(d) >= 0)
	cout << "The double " << d << " occurrs: " << dblBag.find(d)  << " times in the bag" << endl;
	else
	cout << "Bag does not contain " << d << endl; 
    
    return 0;
}
