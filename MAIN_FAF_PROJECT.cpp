#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <limits>

using namespace std;

struct PlayerStats
{
    int runs, wickets, catches;
    double battingAverage;
};

struct Match
{
    string matchType, opponent, date, time, venue;
};

struct Question
{
    string questionText, correctAnswer1, correctAnswer2, correctAnswer3;
};

struct Player
{
    string name;
    int runs;
    double average;
};

struct ICCEvent
{
    string eventType, hostCountry, date;
};

// Function prototypes
void displayMainMenu(); // 1
void displayTeamMenu(); // 2
void displayPakistanTeamStats(); // 3
void displayIndiaTeamStats(); // 4
void displayEnglandTeamStats(); // 5
void displayAustraliaTeamStats(); // 6
void displaySchedule(const vector<Match>& schedule); // 7
vector<Match> readScheduleFromFile(const string& filename); // 8
int generateRandomNumber(); // 9
int generateRandomNumberForToss(); // 10
int userTossChoice; // 11
int computerTossChoice; // 12
void playToss(); // 13
void playCricketGame(); // 14
vector<Question> createCricketQuestions(); // 15
vector<Question> selectRandomQuestions(const vector<Question>& allQuestions); // 16
int playCricketQuiz(const vector<Question>& questions); // 17
void presentQuestion(const Question& question); // 18
string getUserAnswer(); // 19
bool validateAnswer(const string& userAnswer, const Question& question); // 20
void displayResult(int userScore, int totalQuestions); // 21
void displayPlayingEleven(const vector<Player>& team); // 22
void registerPlayingEleven(vector<Player>& team, int numPlayers); // 23
void inputAndDisplayPlayingEleven(); // 24
void addICCEvent(vector<ICCEvent>& events); // 25
void displayICCEvents(const vector<ICCEvent>& events); // 26
void exitProgram(); // 27

int main(int argc, char ** args)
{
    displayMainMenu();
    return 0;
}

void displayMainMenu()
{
    int choice;
    cout << "--------------------------------------------" << endl;
    cout << "------ Cricket Management Application ------" << endl;
    cout << "--------------------------------------------" << endl << endl;
    cout << "1. Show Important Statistics of ODI CWC23" << endl;
    cout << "2. Register Your Own Team" << endl;
    cout << "3. Play Hand Cricket" << endl;
    cout << "4. Overview of Pakistan Team Schedule" << endl;
    cout << "5. Play Trivia/Quiz" << endl;
    cout << "6. Overview of upcoming ICC Events" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
    cin  >> choice;

    vector<Match> schedule;

    switch (choice)
    {
        case 1:

            displayTeamMenu();

            break;

        case 2:
            inputAndDisplayPlayingEleven();
            break;

        case 3:

            cout << "----------------------------------------------------------" << endl << "Welcome to the The Hand Cricket Game against the Compiler!" << endl << "----------------------------------------------------------" << endl << endl;

            playToss();
            playCricketGame();

            break;

        case 4:
            {
                vector<Match> schedule = readScheduleFromFile("PakistanSchedule.txt");
                displaySchedule(schedule);
                break;
            }


        case 5:
            {

             vector<Question> allCricketQuestions = createCricketQuestions();
             vector<Question> selectedCricketQuestions = selectRandomQuestions(allCricketQuestions);

                cout << endl << "-----------------------------------" << endl;
                cout << "Welcome to the Cricket Trivia Quiz!" << endl;
                cout << "-----------------------------------" << endl;
                cout << "You will be presented with 5 cricket-related questions. Good luck! :D" << endl << endl;

                int userScore = playCricketQuiz(selectedCricketQuestions);

                displayResult(userScore, selectedCricketQuestions.size());
            }

            break;


        case 6:
            {
                vector<ICCEvent> events;
                addICCEvent(events);
                displayICCEvents(events);
                break;
            }

        case 7:

            exitProgram();

            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
    }
}

void displayTeamMenu()
{
    int teamChoice;
    cout << "Choose a team:" << endl;
    cout << "1. Pakistan" << endl;
    cout << "2. India" << endl;
    cout << "3. England" << endl;
    cout << "4. Australia" << endl;
    cout << "Enter the corresponding number: ";
    cin  >> teamChoice;

    switch (teamChoice)
    {
        case 1:
            displayPakistanTeamStats();
            break;

        case 2:
            displayIndiaTeamStats();
            break;

        case 3:
            displayEnglandTeamStats();
            break;

        case 4:
            displayAustraliaTeamStats();
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
    }
}

void displayPakistanTeamStats()
{

    ifstream inputFile("PakistanTeamStats.txt");
    if (!inputFile)
    {
        cerr << "Error opening file: PakistanTeamStats.txt" << endl;
        return;
    }

    vector<string> players;
    vector<PlayerStats> stats;
    string playerName;
    PlayerStats player;
    while (inputFile >> playerName >> player.runs >> player.wickets >> player.catches >> player.battingAverage)
    {
        players.push_back(playerName);
        stats.push_back(player);
    }

    inputFile.close();


    cout << "----------------------" << endl << "Pakistan Playing XI Statistics:" << endl << "----------------------" << endl;

    for (size_t i = 0; i < players.size(); ++i)
    {
        cout << players[i] << endl << "Runs - " << stats[i].runs << ", Wickets - " << stats[i].wickets << ", Catches - " << stats[i].catches << ", Batting Average - " << stats[i].battingAverage << endl << "----------------------" << endl;
    }
}

void displayIndiaTeamStats()
{
    ifstream inputFile("IndiaTeamStats.txt");
    if (!inputFile)
    {
        cerr << "Error opening file: IndiaTeamStats.txt" << endl;
        return;
    }

    vector<string> players;
    vector<PlayerStats> stats;
    string playerName;
    PlayerStats player;

    while (inputFile >> playerName >> player.runs >> player.wickets >> player.catches >> player.battingAverage)
    {
        players.push_back(playerName);
        stats.push_back(player);
    }

    inputFile.close();

    cout << "----------------------" << endl << "India Playing XI Statistics:" << endl << "----------------------" << endl;

    for (size_t i = 0; i < players.size(); ++i)
    {
        cout << players[i] << endl << "Runs - " << stats[i].runs << ", Wickets - " << stats[i].wickets << ", Catches - " << stats[i].catches << ", Batting Average - " << stats[i].battingAverage << endl << "----------------------" << endl;
    }

}

void displayEnglandTeamStats()
{
    ifstream inputFile("EnglandTeamStats.txt");
    if (!inputFile)
    {
        cerr << "Error opening file: EnglandTeamStats.txt" << endl;
        return;
    }

    vector<string> players;
    vector<PlayerStats> stats;
    string playerName;
    PlayerStats player;

    while (inputFile >> playerName >> player.runs >> player.wickets >> player.catches >> player.battingAverage)
    {
        players.push_back(playerName);
        stats.push_back(player);
    }

    inputFile.close();

    cout << "----------------------" << endl << "England Playing XI Statistics:" << endl << "----------------------" << endl;

    for (size_t i = 0; i < players.size(); ++i)
    {
        cout << players[i] << endl << "Runs - " << stats[i].runs << ", Wickets - " << stats[i].wickets << ", Catches - " << stats[i].catches << ", Batting Average - " << stats[i].battingAverage << endl << "----------------------" << endl;
    }
}

void displayAustraliaTeamStats()
{
    ifstream inputFile("AustraliaTeamStats.txt");
    if (!inputFile)
    {
        cerr << "Error opening file: AustraliaTeamStats.txt" << endl;
        return;
    }

    vector<string> players;
    vector<PlayerStats> stats;
    string playerName;
    PlayerStats player;

    while (inputFile >> playerName >> player.runs >> player.wickets >> player.catches >> player.battingAverage)
    {
        players.push_back(playerName);
        stats.push_back(player);
    }

    inputFile.close();

    cout << "----------------------" << endl << "Australia Playing XI Statistics:" << endl << "----------------------" << endl;

    for (size_t i = 0; i < players.size(); ++i)
    {
        cout << players[i] << endl << "Runs - " << stats[i].runs << ", Wickets - " << stats[i].wickets << ", Catches - " << stats[i].catches << ", Batting Average - " << stats[i].battingAverage << endl << "----------------------" << endl;
    }
}


void displaySchedule(const vector<Match>& schedule)
{
    cout << endl << "Pakistan Team Schedule:" << endl;
    cout << "------------------------" << endl << endl;

    for (int i = 0; i < schedule.size(); ++i)
    {
    cout << "Match Type: " << schedule[i].matchType << endl;
    cout << "Opponent: " << schedule[i].opponent << endl;
    cout << "Date: " << schedule[i].date << endl;
    cout << "Time: " << schedule[i].time << endl;
    cout << "Venue: " << schedule[i].venue << endl << endl << "------------------------" << endl << endl;
    }
}

vector<Match> readScheduleFromFile(const string& filename)
{
    vector<Match> schedule;
    ifstream inputFile(filename);

    if (!inputFile)
    {
        cerr << "Error opening file: " << filename << endl;
        return schedule;
    }

    string matchType, opponent, date, time, venue;
    while (inputFile >> matchType >> opponent >> date >> time >> venue)
    {
        // Consume the rest of the line to avoid issues with getline
        inputFile.ignore(numeric_limits<streamsize>::max(), '\n');

        schedule.push_back({matchType, opponent, date, time, venue});
    }

    inputFile.close();
    return schedule;
}


int generateRandomNumberForToss ()
{
 srand(time(NULL));

    int randomNumber = rand() % 2;

    randomNumber += 1;

    return randomNumber;
}

int generateRandomNumber()
{
    srand(static_cast<unsigned int>(time(0)));

    return rand() % 6 + 1;
}

void playToss()
{
    cout << "Hi skipper! Let's play the toss to decide for Head or Tail." << endl << endl << "You have to correctly guess and input the same choice you think opposition captain will input: " << endl << endl;

    int userChoice;

    do {
        cout << "Input 1 for Head or 2 for Tail: " << endl;
        cin >> userTossChoice;

        while (userTossChoice != 1 && userTossChoice != 2)
        {
            cout << endl << "Nah! Invalid input skipper. Enter 1 for Head or 2 for Tail: " << endl;
            cin >> userTossChoice;
        }

        computerTossChoice = generateRandomNumberForToss();

        cout << endl << "Compiler's Toss Choice: " << endl << computerTossChoice << endl;

        if (userTossChoice == computerTossChoice)
        {
            cout << endl << "You won the toss! Choose KING Babar (1) or EAGLE Shaheen (2): " << endl;
            cin >> userChoice;

            while (userChoice != 1 && userChoice != 2)
            {
                cout << endl << "Invalid input, skipper. Choose Muhammad Rizwan (1) or Naseem Shah (2): " << endl;
                cin >> userChoice;
            }

            if (userChoice == 1)
            {
                cout << endl << "Great! You chose to bat alongside KING Babar!" << endl;
            }
            else if (userChoice == 2)
            {
                cout << endl << "Wow! You chose to bowl alongside EAGLE Shaheen!" << endl;
            }
        }
        else
        {
            cout << endl << "You lost! Another chance..." << endl << endl;
        }
    } while (userTossChoice != computerTossChoice);
}


void playCricketGame()
{
    int target = 0;
    int userRuns = 0;

    if (userTossChoice == 1)
    {
        cout << endl << "You are facing Shaheen. Try to set maximum runs against him!" << endl;

        do
        {
            cout << endl << "Input your shot between 1 and 6: " << endl;
            int userRun;
            cin  >> userRun;

            while (userRun < 1 || userRun > 6)
            {
                cout << endl << "Invalid shot Babar. Input a shot between 1 and 6: " << endl;
                cin  >> userRun;
            }

            int computerGuess = generateRandomNumber();

            cout << endl << "Shaheen's Input " << computerGuess << endl;

            if (userRun == computerGuess)
            {
                cout << endl << "Ah! Shaheen dismissed you with a beautiful delivery." << endl << "Babar's final score: " << userRuns << " runs." << endl;
                break;
            }

            userRuns += userRun;

            cout << endl << "KING Babar standing on " << userRuns << " runs." << endl;

        }
        while (true);
    }
    else if (userTossChoice == 2)
    {
        cout << endl << "Your turn to bowl. Try to dismiss Babar!" << endl;

        int compilerRuns = 0;

        do
        {
            int computerBowl = generateRandomNumber();

            cout << endl << "So Shaheen, where will you bowl? (between 1 and 6): " << endl;
            int userGuess;
            cin  >> userGuess;

            while (userGuess < 1 || userGuess > 6)
            {
                cout << endl << "Oops! That is a no ball. Try again a number between 1 and 6. " << endl;
                cin  >> userGuess;
            }

            cout << endl << "Babar played the shot for a " << computerBowl << endl;

            if (userGuess == computerBowl)
            {
                cout << endl << "WOAH! You CLEAN BOWLED KING Babar!!! :D" << endl << endl;
                break;
            }

            compilerRuns += computerBowl;
            cout << endl << "Babar's current score: " << compilerRuns << endl;

            cout << endl << "No wicket! Keep trying hard. :) " << endl;

        } while (true);

        cout << endl << "KING Babar's final score: " << compilerRuns << endl << endl;

    }
}

vector<Question> createCricketQuestions()
{
    vector<Question> cricketQuestions(25);

    cricketQuestions[0].questionText = "Who holds the record for the highest individual score in Test cricket?";
    cricketQuestions[0].correctAnswer1 = "Brian Lara";
    cricketQuestions[0].correctAnswer2 = "brian lara";

    cricketQuestions[1].questionText = "Who is known as the 'Sultan of Swing'?";
    cricketQuestions[1].correctAnswer1 = "Wasim Akram";
    cricketQuestions[1].correctAnswer2 = "wasim akram";


    cricketQuestions[2].questionText = "Which country has won the most ICC Cricket World Cups?";
    cricketQuestions[2].correctAnswer1 = "Australia";
    cricketQuestions[2].correctAnswer2 = "australia";

    cricketQuestions[3].questionText = "Which country won the ODI World Cup in 2023?";
    cricketQuestions[3].correctAnswer1 = "Australia";
    cricketQuestions[3].correctAnswer2 = "australia";

    cricketQuestions[4].questionText = "When did Pakistan win ODI WC?";
    cricketQuestions[4].correctAnswer1 = "1992";
    cricketQuestions[4].correctAnswer2 = "92";

    cricketQuestions[5].questionText = "Who was captain of Pakistan when they won ODI WC?";
    cricketQuestions[5].correctAnswer1 = "Imran Khan";
    cricketQuestions[5].correctAnswer2 = "imran khan";

    cricketQuestions[6].questionText = "In cricket, what does LBW stand for?";
    cricketQuestions[6].correctAnswer1 = "Leg Before Wicket";
    cricketQuestions[6].correctAnswer2 = "leg before wicket";

    cricketQuestions[7].questionText = "Who is the current captain of the Indian cricket team?";
    cricketQuestions[7].correctAnswer1 = "Rohit Sharma";
    cricketQuestions[7].correctAnswer2 = "rohit sharma";

    cricketQuestions[8].questionText = "Which cricket stadium is known as \"The Home of Cricket\"?";
    cricketQuestions[8].correctAnswer1 = "Lords";
    cricketQuestions[8].correctAnswer2 = "lords";

    cricketQuestions[9].questionText = "What does ICC stand for in the context of cricket?";
    cricketQuestions[9].correctAnswer1 = "International Cricket Council";
    cricketQuestions[9].correctAnswer2 = "internatonal cricket council";

    cricketQuestions[10].questionText = "How many players are there in a cricket team?";
    cricketQuestions[10].correctAnswer1 = "11";
    cricketQuestions[10].correctAnswer2 = "eleven";
    cricketQuestions[10].correctAnswer3 = "Eleven";

    cricketQuestions[11].questionText = "What is the length of a cricket pitch in yards?";
    cricketQuestions[11].correctAnswer1 = "20 meter";
    cricketQuestions[11].correctAnswer2 = "22 yards";
    cricketQuestions[11].correctAnswer3 = "22 yard";

    cricketQuestions[12].questionText = "What is the nickname of the Pakistan cricket team?";
    cricketQuestions[12].correctAnswer1 = "Unpredictable";
    cricketQuestions[12].correctAnswer2 = "unpredictable";

    cricketQuestions[13].questionText = "Who is known as \"Boom Boom\"?";
    cricketQuestions[13].correctAnswer1 = "Shahid Afridi";
    cricketQuestions[13].correctAnswer2 = "shahid afridi";

    cricketQuestions[14].questionText = "In cricket, what does IPL stand for?";
    cricketQuestions[14].correctAnswer1 = "Indian Premier League";
    cricketQuestions[14].correctAnswer2 = "indian premier league";

    cricketQuestions[15].questionText = "In cricket, what does PSL stand for?";
    cricketQuestions[15].correctAnswer1 = "Pakistan Super League";
    cricketQuestions[15].correctAnswer2 = "pakistan super league";

    cricketQuestions[16].questionText = "Who is the current captain of the Australian cricket team?";
    cricketQuestions[16].correctAnswer1 = "Pat Cummins";
    cricketQuestions[16].correctAnswer2 = "pat cummins";

    cricketQuestions[17].questionText = "How many legal deliveries are bowled in a T20i match?";
    cricketQuestions[17].correctAnswer1 = "120";
    cricketQuestions[17].correctAnswer2 = "";

    cricketQuestions[18].questionText = "How many legal deliveries are bowled in a ODI match?";
    cricketQuestions[18].correctAnswer1 = "300";

    cricketQuestions[19].questionText = "Who is known as the \"Rawalpindi Express\" in cricket?";
    cricketQuestions[19].correctAnswer1 = "Shoaib Akhtar";
    cricketQuestions[19].correctAnswer2 = "shoaib akhtar";

    cricketQuestions[20].questionText = "Who is Bobbzy the King?";
    cricketQuestions[20].correctAnswer1 = "Babar Azam";
    cricketQuestions[20].correctAnswer2 = "babar azam";

    cricketQuestions[21].questionText = "What is the duration of a Test match?";
    cricketQuestions[21].correctAnswer1 = "5 days";

    cricketQuestions[22].questionText = "Who is called \"The Universe Boss\" in Cricket?";
    cricketQuestions[22].correctAnswer1 = "Chris Gayle";
    cricketQuestions[22].correctAnswer2 = "chris gayle";

    cricketQuestions[23].questionText = "Who was Pakistan team captain in Champions Trophy 2017?";
    cricketQuestions[23].correctAnswer1 = "Sarfaraz Ahmed";
    cricketQuestions[23].correctAnswer2 = "sarfaraz ahmed";

    cricketQuestions[24].questionText = "Who is called Superman in Team Pakistan?";
    cricketQuestions[24].correctAnswer1 = "Muhammad Rizwan";
    cricketQuestions[24].correctAnswer2 = "muhammad rizwan";

    return cricketQuestions;
}

vector<Question> selectRandomQuestions(const vector<Question>& allQuestions)
{
    srand(time(NULL));

    vector<Question> selectedQuestions;
    vector<int> indices;

    while (indices.size() < 6)
    {
        int index = rand() % 25;
        if (find(indices.begin(), indices.end(), index) == indices.end())
        {
            indices.push_back(index);
        }
    }

    for (int index : indices)
    {
        selectedQuestions.push_back(allQuestions[index]);
    }

    return selectedQuestions;
}

void presentQuestion(const Question& question)
{
    cout << "Question: " << question.questionText << endl;
}

string getUserAnswer()
{
    string userAnswer;
    cout << "Your answer: ";
    getline(cin, userAnswer);
    return userAnswer;
}

bool validateAnswer(const string& userAnswer, const Question& question)
{
    return (userAnswer == question.correctAnswer1 || userAnswer == question.correctAnswer2 || userAnswer == question.correctAnswer3 );
}

void displayResult(int userScore, int totalQuestions)
{
    cout << endl << "Quiz completed! Your score: " << userScore << "/" << totalQuestions << endl;
}

int playCricketQuiz(const vector<Question>& questions)
{
    int score = 0;
    int totalQuestions = questions.size();

    for (const Question& question : questions)
    {
        presentQuestion(question);
        string userAnswer = getUserAnswer();
        if (validateAnswer(userAnswer, question))
        {
            cout << "Correct!" << endl << endl;
            score++;
        }
        else
        {
            cout << "Incorrect!" << endl << endl;
        }
    }

    return score;
}

void displayPlayingEleven(const vector<Player>& team)
{
    cout << "\nPlaying Eleven:" << endl;
    for (const auto& player : team)
    {
        cout << "Name: " << player.name << ", Runs: " << player.runs << ", Average: " << player.average << endl;
    }
}

void registerPlayingEleven(vector<Player>& team, int numPlayers)
{
    cout << "Enter details for Playing XI:" << endl;
    for (int i = 0; i < numPlayers; ++i)
    {
        Player player;
        cout << "Player " << i + 1 << " name: ";
        getline(cin >> ws, player.name); // Use getline to allow spaces in player name

        cout << "Player " << i + 1 << " runs: ";
        cin  >> player.runs;

        cout << "Player " << i + 1 << " average: ";
        cin  >> player.average;

        team.push_back(player);
        cin.ignore(); // Ignore newline character left in the buffer
    }
}

void inputAndDisplayPlayingEleven()
{
    int numPlayers;
    cout << "-----------------------------------------" << endl;
    cout << "Enter the number of players in your team: ";
    cin  >> numPlayers;
    cout << "-----------------------------------------" << endl;
    cin.ignore(); // Ignore newline character left in the buffer

    vector<Player> playingEleven;
    registerPlayingEleven(playingEleven, numPlayers);
    displayPlayingEleven(playingEleven);
}

void addICCEvent(vector<ICCEvent>& events)
{
    events.push_back({"ICC T20i World Cup", "West Indies & United States of America", "June 2024"});
    events.push_back({"ICC Champions Trophy", "Pakistan", "February 2025"});
    events.push_back({"ICC World Test Championship", "England", "June 2025"});
    events.push_back({"ICC T20i World Cup","India & Sri Lanka", "February 2026"});
    events.push_back({"ICC ODi World Cup", "South Africa, Zimbabwe & Namibia", "October 2027"});
    events.push_back({"ICC T20i World Cup", "Australia & New Zealand", "October 2028"});
    events.push_back({"ICC Champions Trophy ", "India", "October 2029"});
    events.push_back({"ICC T20i World Cup", "England, Wales, Ireland & Scotland", "June 2030"});
    events.push_back({"ICC ODi World Cup", "India & Bangladesh", "October 2031"});
}

void displayICCEvents(const vector<ICCEvent>& events)
{
    cout << "--------------------------------------------" << endl;
    cout << "Upcoming ICC Events" << endl;
    cout << "--------------------------------------------" << endl;

    for (const ICCEvent& event : events)
    {
        cout << endl <<"Event Type: " << event.eventType << endl << endl;
        cout << "Host Country: " << event.hostCountry << endl << endl;
        cout << "Date: " << event.date << endl << endl;
        cout << "--------------------------------------------" << endl;
    }
}

void exitProgram()
{
    cout << endl << "---------------------------------------------------------------" << endl;
    cout << "Thank you for using the Cricket Management Application. Goodbye! :)" << endl;
    cout << "---------------------------------------------------------------" << endl;

    exit(0);
}
