#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

enum enLevel
{
    EasyLevel = 1,
    MedLevel  = 2,
    HardLevel = 3,
    MixLevel  = 4
};
enum enOp
{
    Add = 1,
    Sub = 2,
    Mul = 3,
    Div = 4,
    Mix = 5
};

int RandNum(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

int ReadIntNumber(string Message)
{
    int Number;
    while (true)
    {
        cout << Message;
        cin >> Number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid Input! Please enter a valid number."<<endl;
        }
        else
        {
            return Number;
        }
    }
}

// ================= Inputs =================
int AskNumberOfQuestions()
{
    int Number;
    do
    {
        Number = ReadIntNumber("Enter number of Questions? ");
    } while (Number < 1);
    return Number;
}

enLevel GetUserLevel()
{
    int level;
    do
    {
        level = ReadIntNumber("Enter Questions level [1]Easy, [2]Med, [3]Hard, [4]Mix: ");
    } while (level < 1 || level > 4);
    return (enLevel)(level);
}

enOp GetUserType()
{
    int Op;
    do
    {
        Op = ReadIntNumber("Enter operation type [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix: ");
    } while (Op < 1 || Op > 5);
    return (enOp)(Op);
}

enOp GetRandomOperation()
{
    return (enOp)RandNum(1, 4);
}

// ================= Converting To String =================
string LevelToString(enLevel level)
{
    switch (level)
    {
    case EasyLevel:
        return "Easy";
    case MedLevel:
        return "Med";
    case HardLevel:
        return "Hard";
    case MixLevel:
        return "Mix";
    default:
        return "Unknown";
    }
}

string TypeToString(enOp type)
{
    switch (type)
    {
    case Add:
        return "+";
    case Sub:
        return "-";
    case Mul:
        return "*";
    case Div:
        return "/";
    case Mix:
        return "Mix";
    default:
        return "Unknown";
    }
}

// ================= Question Struct =================
struct stQuestion
{
    int Num1 = 0;
    int Num2 = 0;
    enOp OperationType;
    enLevel QuestionLevel;
    int PlayerAnswer = 0;
    int CorrectAnswer = 0;
    bool AnswerResult = false;
};

// ================= Calculator =================
int SimpleCalc(int Num1, int Num2, enOp Op)
{
    switch (Op)
    {
    case Add:
        return Num1 + Num2;
    case Sub:
        return Num1 - Num2;
    case Div:
        return Num1 / Num2;
    case Mul:
        return Num1 * Num2;
    default:
        return 0;
    }
}

// ================= Generate Question =================
stQuestion GenerateQuestion(enLevel QuestionLevel, enOp OpType)
{
    stQuestion Question;

    Question.QuestionLevel = (QuestionLevel == MixLevel) ? (enLevel)RandNum(1, 3) : QuestionLevel;
    Question.OperationType = (OpType == Mix) ? GetRandomOperation() : OpType;

    switch (Question.QuestionLevel)
    {
    case EasyLevel:
        Question.Num1 = RandNum(1, 10);
        Question.Num2 = RandNum(1, 10);
        break;
    case MedLevel:
        Question.Num1 = RandNum(10, 50);
        Question.Num2 = RandNum(10, 50);
        break;
    case HardLevel:
        Question.Num1 = RandNum(50, 100);
        Question.Num2 = RandNum(50, 100);
        break;
    }

    if (Question.OperationType == Div)
    {
        Question.Num2 = RandNum(1, 10);
        Question.Num1 = Question.Num2 * RandNum(1, 10);
    }

    Question.CorrectAnswer = SimpleCalc(Question.Num1, Question.Num2, Question.OperationType);
    return Question;
}

// ================= Play Round =================
bool PlayRound(int RoundNumber, enLevel Level, enOp OpType)
{
    stQuestion Question = GenerateQuestion(Level, OpType);

    cout << "\n==================== Question [" << RoundNumber << "] ======================\n";
    cout << Question.Num1 << " " << TypeToString(Question.OperationType) << " " << Question.Num2 << " = ";
    Question.PlayerAnswer = ReadIntNumber("");

    if (Question.PlayerAnswer == Question.CorrectAnswer)
    {
        cout << "Correct Answer :-)\n";
        return true;
    }
    else
    {
        cout << "Wrong Answer :-(\n";
        cout << "The correct answer is: " << Question.CorrectAnswer << endl;
        return false;
    }
}

// ================= Start Game =================
void StartGame()
{
    int QuestionsCount = AskNumberOfQuestions();
    enLevel Level = GetUserLevel();
    enOp OpType = GetUserType();

    int CorrectAnswersCount = 0;
    int WrongAnswersCount = 0;

    for (int i = 1; i <= QuestionsCount; i++)
    {
        if (PlayRound(i, Level, OpType))
            CorrectAnswersCount++;
        else
            WrongAnswersCount++;
    }

    cout << "\n===============================================\n";
    cout << "                 GAME OVER                       \n";
    cout << "===============================================\n";
    cout << " Number of Questions: " << QuestionsCount << endl;
    cout << " Questions Level    : " << LevelToString(Level) << endl;
    cout << " Operation Type     : " << TypeToString(OpType) << endl;
    cout << " Correct Answers    : " << CorrectAnswersCount << endl;
    cout << " Wrong Answers      : " << WrongAnswersCount << endl;
    cout << " Final Result       : " << (CorrectAnswersCount >= WrongAnswersCount ? "PASS :)" : "FAIL :(") << endl;
    cout << "===============================================\n";
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();
    return 0;
}