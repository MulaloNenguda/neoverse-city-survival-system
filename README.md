NEOVERSE: AI CITY SURVIVAL SYSTEM

1. SYSTEM DESCRIPTION

NeoVerse is a console-based C++ city survival simulation system. The system demonstrates the use of object-oriented programming, STL containers, STL algorithms, file handling and Big-O analysis.

2. HOW TO RUN THE PROGRAM

1. Open the NeoVerse project in Microsoft Visual Studio.
2. Build the project.
3. Run the program.
4. Enter one of the sample engineer credentials below.
5. The system will display the city data, process events and emergencies, demonstrate the city component systems, generate reports and save the system data.

3. SAMPLE LOGIN CREDENTIALS

Engineer 1:
Username: engineer1
Password: password123
Clearance: High

Engineer 2:
Username: engineer2
Password: city456
Clearance: Medium

4. CONTAINERS USED

vector:
Used to store engineers and daily sensor readings. A vector provides fast random access and can dynamically grow as data is added.

list:
Used for historical city logs. A linked list allows elements to be inserted and removed without requiring the entire collection to be shifted.

queue:
Used for incoming city events. Events are processed using FIFO (First In, First Out).

stack:
Used for emergency overrides. Emergencies are handled using LIFO (Last In, First Out).

5. STL ALGORITHMS USED

sort:
Used to arrange sensor readings in ascending order.

find:
Used to search for engineer credentials and a specific sensor value.

min_element:
Used to find the lowest sensor reading.

max_element:
Used to find the highest sensor reading.

count_if:
Used to count critical sensor alerts.

6. BIG-O DECISIONS

Linear search is O(n) because elements may need to be checked one at a time.

Binary search is O(log n), but it requires sorted data.

Vector random access is O(1). 

Searching through a list is O(n).

Efficient STL sorting operates in O(n log n) complexity.

Queue insertion and removal from the appropriate ends are O(1).

Stack push and pop operations are O(1).

7. OBJECT-ORIENTED PROGRAMMING

The program demonstrates encapsulation through private class attributes and public member functions.

Inheritance is demonstrated by PowerSystem, TransportSystem, HealthSystem and SecuritySystem inheriting from CityComponent.

Polymorphism is demonstrated through the virtual processEvent() function.

Constructors and destructors are used in the city component classes.

8. FILES USED

engineers.dat
Stores engineer information including encrypted passwords.

events.dat
Stores city event information.

city_logs.dat
Stores sensor readings and historical city logs.

config.txt
Stores system configuration information.

README.txt
Provides instructions and explanations for the system.

9. FILE PERSISTENCE

The system loads existing data when it starts and saves system data when the simulation finishes.

10. LOGIN PASSWORD NOTE

The password encryption used in this educational project is a simple character-shifting method. It demonstrates the concept of storing an encrypted password for the assignment and is not intended to provide real-world password security.
