// project4_jtg0040.cpp
// John Guess
// jtg0040
// learned about getline from http://www.cplusplus.com/reference/string/string/getline/
// To compile code, either leave the following line in to compile a debug Version
// or remove the line to compile the user Version.
#define UNIT_TESTING

#include <string>
#include <iostream>
#include <assert.h>
using namespace std;
struct node
{
  string question;
  string answer;
  int points;
  struct node *next;
};
node* createFirstThreeQuestions();
void createNode(node* firstQuestion);
int askQuestion(node* firstQuestion, int questionNumber);

#ifdef UNIT_TESTING
int main() {
  int playerPoints = 0;
  cout << "\n*** This is a debugging version ***\n";
  cout << "Unit Test Case 1: Ask no questions. The program should give a warning message\n";
  askQuestion(NULL, 1);

  cout << "\nUnit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer.\n";
  node* firstQuestion = createFirstThreeQuestions();
  playerPoints += askQuestion(firstQuestion, 1);
  assert(playerPoints == 0);
  cout << "Case 2.1 passed...\n\n";

  cout << "\nUnit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer.\n";
  playerPoints = 0;
  playerPoints += askQuestion(firstQuestion, 3);
  assert(playerPoints = 20);
  cout << "Case 2.2 passed... \n\n";

  cout << "\nUnit Test Case 3: Ask all three questions of the last trivia in the linked list.\n";
  askQuestion(firstQuestion, 1);
  cout << "\n";
  askQuestion(firstQuestion, 2);
  cout << "\n";
  askQuestion(firstQuestion, 3);
  cout << "\nCase 3 passed... \n\n";

  cout << "\nUnit Test Case 4: Ask five questions in the linked list.\n";
  askQuestion(firstQuestion, 5);

  cout << "\n*** End of the Debugging Version ***\n\n";
}

#else
int main() {
  int playerPoints = 0;
  node* question1 = createFirstThreeQuestions();
  cout << "\n\n*** Welcome to John's trivia quiz game ***\n";

  string contin = "Yes";
  while (contin == "Yes") {
    createNode(question1);
    cout << "Coninue? (Yes/No) ";
    getline(cin, contin);
  }
  cout << "\n";

  node* questionPointer = question1;
  int questionCounter = 1;
  while (questionPointer != NULL) {
    cout << "\n";
    playerPoints += askQuestion(question1, questionCounter);
    cout << "Your total points: " << playerPoints << "\n";
    questionPointer = questionPointer->next;
    questionCounter ++;
  }

  cout << "\nCongratulations! You have won " << playerPoints << " points!\n\n";
  cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
}
#endif

#include <string>
#include <iostream>
using namespace std;

node* createFirstThreeQuestions() {
  node* question1 = new node;
  question1->question = "How long was the shortest war on record? (Hint: how many minutes)";
  question1->answer = "38";
  question1->points = 100;

  node* question2 = new node;
  question2->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
  question2->answer = "Bank of Italy";
  question2->points = 50;

  node* question3 = new node;
  question3->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
  question3->answer = "Wii Sports";
  question3->points = 20;

  question1->next = question2;
  question2->next = question3;
  question3->next = NULL;

  return question1;
}

void createNode(node* firstQuestion) {
  node* newQuestion = new node;
  cout << "Enter a question: ";
  string newQuestionTitle;
  getline(cin, newQuestionTitle);

  cout << "Enter an answer: ";
  string newAnswer;
  getline(cin, newAnswer);

  cout << "Enter award points: ";
  int newPoints;
  cin >> newPoints;
  cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

  newQuestion->question = newQuestionTitle;
  newQuestion->answer = newAnswer;
  newQuestion->points = newPoints;
  newQuestion->next = NULL;

  node* questionPointer = firstQuestion;
  while (questionPointer->next != NULL) {
    questionPointer = questionPointer->next;
  }
  questionPointer->next = newQuestion;
}

int askQuestion(node* firstQuestion, int questionNumber) {
  if (firstQuestion == NULL) {
    cout << "Warning – The number of trivia to be asked must equal to or larger than 1\n";
    return -1;
  }
  node* pointer = firstQuestion;
  for (int i = 1; i < questionNumber; i++) {
    if (pointer->next != NULL) {
      pointer = pointer->next;
    } else {
      cout << "Warning - There are only three trivia in the list.\n";
      return -1;
    }
  }
  cout << "Question: " << pointer->question << "\nAnswer: ";
  string userInput;
  getline(cin, userInput);

  if (userInput == pointer->answer) {
    cout << "Your answer is correct. You receive " << pointer->points << " points.\n";
    return pointer->points;
  } else {
    cout << "Your answer is wrong. The correct answer is: " << pointer->answer << "\n";
    return 0;
  }
}
