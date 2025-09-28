#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>   // потрібен для runtime_error
#include <fstream>

using namespace std;

struct Time
{
private:
    short h, m, s;
public:
    Time() :h{ 0 }, m{ 0 }, s{ 0 } {};
    Time(short h, short m, short s) :h{ h }, m{ m }, s{ s } {};
    int timeInSeconds() const {
        return h * 3600 + m * 60 + s;
    }

    string print() const {
        return to_string(h) + ":" + to_string(m) + ":" + to_string(s);
    }

    friend ostream& operator<<(ostream& out, const Time& t);
};

class Train
{
private:
    int number;
    Time departureTime;
    string destination;

public:
    Time getDepartureTime() const {
        return departureTime;
    }
    Train() : number{ 0 }, departureTime(), destination{ "" } {}
    Train(int number, Time departureTime, string destination)
        : number{ number }, departureTime{ departureTime }, destination{ destination } {
    }

    int getNumber() const {
        return number;
    }
    string getDestination() const {
        return destination;
    }

    void fixDepartureTimeByNumber(int number) {
        if (this->number == number) {
            cout << "Enter new departure time (h m s): ";
            short h, m, s;
            cin >> h >> m >> s;
            departureTime = Time(h, m, s);
        }
    }

    int getDepartureTimeInSeconds() const {
        return departureTime.timeInSeconds();
    }

    
    friend ostream& operator<<(ostream& out, const Train& tr);
};

class Railway
{
    vector<Train> trains;

public:
    void addTrain(Train train)
    {
        for (auto& tr : trains)
        {
            if (train.getNumber() == tr.getNumber())
                throw runtime_error("Train with this number already exists");
        }
        trains.push_back(train);
    }

    int getTrainCount() const
    {
        return trains.size();
    }

    void printTrains() const
    {
        cout << "--- Trains ---" << endl;
        for (const auto& tr : trains)
        {
            cout << tr << endl;
        }
        cout << "--------------" << endl;
    }

    void fixDepartureTimeByNumber(int number) {
        for (auto& tr : trains) {
            tr.fixDepartureTimeByNumber(number);
        }
    }

    void getInfoByNumber(int number) {
        for (auto& t : trains)
        {
            if (t.getNumber() == number) {
                cout << t << endl;
                return;
            }
        }
        cout << "Train #" << number << " not found" << endl;
    }

    void sortByTimeDeparture() {
        for (int i = 0; i < trains.size(); i++)
            for (int j = 0; j <trains.size() - 1; j++)
                if (trains[j].getDepartureTimeInSeconds() > trains[j + 1].getDepartureTimeInSeconds())
                    swap(trains[j], trains[j + 1]); 
    }

    void printTrainsByDestination(string destination) const {
        cout << "--- Trains to " << destination << " ---" << endl;
        for (auto& tr : trains) {
            if (tr.getDestination() == destination) {
                cout << tr << endl;
            }
        }
        cout << "------------------------------" << endl;
    }
};

ostream& operator<<(ostream& out, const Time& t)
{
    out << t.print();
    return out;
}

ostream& operator<<(ostream& out, const Train& tr)
{
    out << left << setw(4) << tr.getNumber()
        << setw(10) << tr.getDepartureTime()   
        << setw(20) << tr.getDestination();
    return out;
}



int main()
{
    Railway railway;
    try
    {
        railway.addTrain(Train(101, Time(10, 30, 0), "New York"));
        railway.addTrain(Train(102, Time(9, 15, 0), "Los Angeles"));
        railway.addTrain(Train(103, Time(11, 45, 0), "Chicago"));
        railway.addTrain(Train(104, Time(8, 0, 0), "New York"));
        railway.addTrain(Train(105, Time(12, 30, 0), "Miami"));
    }
    catch (const exception& ex)
    {
        cerr << ex.what() << endl;
    }
    railway.printTrains();

    int trainNumber;
    cout << "Enter train number to fix departure time: ";
    cin >> trainNumber;
    railway.fixDepartureTimeByNumber(trainNumber);
    railway.printTrains();

    cout << "Enter train number to get info: ";
    cin >> trainNumber;
    railway.getInfoByNumber(trainNumber);

    railway.sortByTimeDeparture();
    cout << "Trains sorted by departure time:" << endl;
    railway.printTrains();

    string destination;
    cout << "Enter destination to filter trains: ";
    cin >> destination;
    railway.printTrainsByDestination(destination);
	//я не придуамв як записати в файл, тому що не зовсім розумію формат

}
