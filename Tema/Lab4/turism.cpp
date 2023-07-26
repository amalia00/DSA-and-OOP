/*
Name:Borde Amalia

Group: 811

Assigment 3-4

Problem 4: Tourism Agency

*/
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "turism.h"
using namespace std;

void Menu()
{
	cout << "0 -> exit\n";
	cout << "1 -> add a tourism offer\n";
	cout << "2 -> delete a tourism offer\n";
	cout << "3 -> update a tourism offer\n";
	cout << "4 -> display all tourism offers\n";
	cout << "5 -> display all the tourism offers with the same destination\n";
	cout << "6 -> display all offers of a given type, starting from a given date.\n";

}


int main()
{
	vector<Turism> Agency;
	int option;
	Menu();
	cin >> option;
	float price = 0;
	int date = 0, month = 0;
	string type,destination;
	while (option != 0)
	{
		if (option == 1)
			AddOffer(Agency, price, date, month, destination,type);
		/*if (option == 2)
			DeleteOffer(Agency, date,month,destination);
		if (option == 3)
			UpdateOffer(Agency, date, month, destination);*/
		if (option == 4)
			DisplayAllOffers(Agency);
		if (option == 5)
			DisplayDestination(Agency);
		if (option == 6)
			DisplayTyDate(Agency);
		Menu();
		cin >> option;
	}
}
void AddOffer(vector<Turism>& newAgency, float& price, int& date, int& month,string& destination, string& type)
{
	cout << "how many offers you want to add? ";
	int offerNumber;
	cin >> offerNumber;
	for (int i = 0; i < offerNumber; i++)
	{
		cout << "price:";
		cin >> price;
		cout << "date:";
		cin >> date;
		cout << "month:";
		cin >> month;
		cout << "destination:";
		cin >> destination;
		cout << "type:";
		cin >> type;
		Turism newAgency(price, date, month, destination, type);
		newAgency.push_back(newAgency);
		cout << endl;
	}
	cout << endl;
}
/*void DeleteOffer(const vector<Turism>& newAgency,date,month,destination)
{
	int i;
	for (i=0;i< newAgency.size(),i++)
		if (newAgnecy[i].GetDate==date && newAgency[i].GetMonth==month && newAgnecy[i].GetDestination==destination)
			delete newAgency[i]

}*/
void DisplayAllOffers(const vector<Turism>& newAgency)
{
	unsigned int size = newAgency.size();
	for (int i = 0; i < size; i++)
	{
		cout << "price: " << newAgency[i].GetPrice() << endl;
		cout << "type: " << newAgency[i].GetType() << endl;
		cout << "destination: " << newAgency[i].GetDestination() << endl;
		cout << "date: " << newAgency[i].GetDate() << endl;
		cout << "month: " << newAgency[i].GetMonth() << endl;
	}
}
void DisplayDestination(vector<Turism>& newAgency)
{
	string destination;
	cout << "give the destination of the offers you want to display ";
	cin >> destination;
	int ok = 1;
	unsigned int size = newAgency.size();
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
		{
			int comp = newAgency[i].GetDestination().compare(destination);
			if (newAgency[i].GetPrice() > newAgency[j].GetPrice() && comp == 0)
			{
				int aux = newAgency[i].GetPrice();
				newAgency[i].SetPrice(newAgency[j].GetPrice());
				newAgency[j].SetPrice(aux);
				string aux2 = newAgency[i].GetDestination();
				newAgency[i].SetDestination(newAgency[j].GetDestination());
				newAgency[j].SetDestination(aux2);
			}
			else if (comp != 0)//if the type is empty we have to show all offers
			{
				DisplayAllOffers(newAgency);
				ok = 0;
			}
			if (ok == 0)//exit the function
				exit(-1);
		}
	int i = 0;
	while (i < size)//display the offers
	{
		cout << newAgency[i].GetDestination() << " " << newAgency[i].GetPrice() << endl;
		i++;
	}
}
void DisplayTyDate(vector<Turism>& newAgency)
{
	int date, month;
	string type;
	cout << "give the day ypu want the offers to display from: ";
	cin >> date;
	if (date > 31)
	{
		cout << "the date does not exist";
		exit(-1);
	}
	cout << "give the month you want the offers to display from:: ";
	cin >> month;
	if (month > 12 || month<1)
	{
		cout << "the month does not exist";
		exit(-1);
	}
	cout << "choose the type of the offer: ";
	cin >> type;
    int size = newAgency.size();
	for (int i = 0; i < size; i++)
	{
		int comp = newAgency[i].GetType().compare(type);
		if (comp == 0)
		{
			if (newAgency[i].GetMonth() <= month)
			{
				if (newAgency[i].GetDate() <= date)
					cout << newAgency[i].GetType() << " " << newAgency[i].GetDate() << " " << newAgency[i].GetMonth() << endl;
			}
		}
	}

}
