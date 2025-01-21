
#include <iostream>
#include <cstdlib>
using namespace std;

//’My Project Code
/*
enum enQuizLevel { Easy = 1, Med = 2, Hard = 3, QuizMix = 4 };
enum enOprationType { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5 };
enum QeustionAnswer {True = 1, False = 2};


struct stGameResults {
    enQuizLevel  QuestionLevel;
    enOprationType OperationType;
    string OperationTypeName;
    string QuestionLevelName;
    short GameRounds = 0;
    short RightAnswers = 0;
    short WrongAnswers = 0;

};

int RandomNumber(int From, int To) {
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

string Tabs(short NumberOfTabs) {
    string t = "";
    for (int i = 1; i < NumberOfTabs; i++) {
        t = t + "\t";
        cout << t;
    }
    return t;
}

void ShowGameOverScreen() {
    cout << Tabs(2) << "____________________\n\n";
    cout << Tabs(2) << "                 +++ G a m e  O v e r +++\n";
    cout << Tabs(2) << "____________________\n\n";
}

short ReadHowManyRounds()
{
    short GameRounds = 1;
    do {
        cout << "How Many Rounds 1 to 10 ? \n";
        cin >> GameRounds;
    } while (GameRounds < 1 || GameRounds > 10);
    return GameRounds;
}

enQuizLevel ReadQuestionLevel()
{
    short GameLevel = 1;
    do {
        cout << "Question Level : [1] Easy, [2] Med,  [3]Hard, [4]Mix ? \n";
        cin >> GameLevel;
    } while (GameLevel < 1 || GameLevel > 4);
    return (enQuizLevel)GameLevel;
}

enOprationType ReadOperationType()
{
    short Operation = 1;

        cout << "OperationType : [1] Add, [2] Sub,  [3]Mul, [4]Div, [5]Mix ? \n";
        cin >> Operation;

    return (enOprationType)Operation;
}

int GetRandomNumber(enQuizLevel QuestionLevel)
{
    switch(QuestionLevel)
    {
        case enQuizLevel::Easy:
            return RandomNumber(1, 10);
        case enQuizLevel::Med:
            return RandomNumber(11, 30);
        case enQuizLevel::Hard:
            return RandomNumber(30, 90);
        case enQuizLevel::QuizMix:
            return RandomNumber(1, 100);
    }
}


string QuestionLevelName(enQuizLevel  QuestionLevel)
{
    
    string arrQuestionLevs[4] = { "Easy","Mid","Hard","Mix"};
    
    return arrQuestionLevs[QuestionLevel - 1];
}

string RandomOperationType()
{
    short Operation = 1;
    string arrOperation[] = {"+","-","*","/"};

             Operation = RandomNumber(0,3);
          return  arrOperation[Operation];
}

string GetOperationType(enOprationType OperationType)
{
    switch(OperationType)
    {
        case enOprationType::Add:
            return "+";
        case enOprationType::Sub:
            return "-";
        case enOprationType::Mul:
            return "*";
        case enOprationType::Div:
            return "/";
        case enOprationType::Mix:
            return RandomOperationType();
    }
}

int AnswerQuestion(short Number1, short Number2, string Operation)
{
    if(Operation == "+")
    {
        return Number1 + Number2;
    }
    else if(Operation == "-")
    {
        return Number1 - Number2;
    }
    else if (Operation == "*")
    {
        return Number1 * Number2;
    }
    else
    {
        return Number1 / Number2;
    }
}

void CheckAnswers(int PlayerAnswer, int RightAnswer)
{
    if (PlayerAnswer == RightAnswer)
    {
        system("color 2F"); // Turn screen to Green
    }
    else
    {
        system("color 4F"); // Turn screen to Red
        cout << "\nThe Right Answer is: " << RightAnswer << endl;
    }

}

stGameResults FillGameResults(int GameRounds, short TrueAnswer, short FalseAnswer, enOprationType OperationType, enQuizLevel  QuestionLevel) 
{
    stGameResults GameResults;
    GameResults.GameRounds = GameRounds;
    GameResults.RightAnswers = TrueAnswer;
    GameResults.WrongAnswers = FalseAnswer;
    GameResults.QuestionLevel = QuestionLevel;
    GameResults.QuestionLevelName = QuestionLevelName(QuestionLevel);
    GameResults.OperationType = OperationType;
    GameResults.OperationTypeName = GetOperationType(OperationType);
    return GameResults;
}

void ShowFinalGameResults(stGameResults GameResults) {
    cout << Tabs(2) << "_______ [Game Results ]_______\n\n";
    cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRounds << endl;
    cout << Tabs(2) << "Right Answers      : " << GameResults.RightAnswers << endl;
    cout << Tabs(2) << "Wrong Answers      : " << GameResults.WrongAnswers << endl;
    cout << Tabs(2) << "Question Level     : " << GameResults.QuestionLevelName << endl;
    cout << Tabs(2) << "Operation Type     : " << GameResults.OperationTypeName << endl;
    cout << Tabs(2) << "_____________________\n";
    //SetWinnerScreenColor(GameResults.GameWinner);
}

stGameResults PlayGame(enQuizLevel QuestionLevel, enOprationType OperationType,short HowManyRounds ) {

    stGameResults GameInfo;

    short Num1 = 0, Num2 = 0,PlayerAnswer = 0, RightAnswer = 0, TrueAnswers = 0, FalseAnswers = 0 ;
    string OperationName;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        cout << "\nRound [" << GameRound << "/" << HowManyRounds << "]:\n";
        
        Num1 = GetRandomNumber(QuestionLevel); 
        
        Num2 = GetRandomNumber(QuestionLevel);

        GameInfo.OperationTypeName = GetOperationType(OperationType);

        cout << "  " << Num1 << "\n" << "\t" << OperationName << "\n" << "  " << Num2 << "\n__________" << endl;
         cin >> PlayerAnswer;

         RightAnswer = AnswerQuestion(Num1, Num2, OperationName);

         CheckAnswers(PlayerAnswer, RightAnswer);




        // Increase win/Draw counters
        if (PlayerAnswer == RightAnswer)
             TrueAnswers++;
        else 
            FalseAnswers++;


    }

    return FillGameResults(HowManyRounds, TrueAnswers, FalseAnswers, OperationType,QuestionLevel);
}

void ResetScreen() {
    system("cls");
    system("color 0F");
}


void StartGame() {
    char PlayAgain = 'Y';
    do {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadQuestionLevel(), ReadOperationType(), ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);
        cout << endl << Tabs(3) << "Do you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}
*/


//Hadhud Code

enum enQuestionsLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4};
enum enOperationType  { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5};

string GetOpTypeSymbol(enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return "+";
    case enOperationType::Sub:
        return "-";
    case enOperationType::Mult:
        return "x";
    case enOperationType::Div:
        return "/";
    default:
        return "Mix";
    }
}

string GetQuestionLevelText(enQuestionsLevel QuestionLevel)
{
    string arrQuestionLevelText[4] = { "Easy","Med","Hard","Mix"};
    return arrQuestionLevelText[QuestionLevel - 1];
}

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void SetScreenColor(bool Right)
{
    if (Right)
        system("color 2F"); //turn screen to Green
    else
    {
        system("color 4F"); //turn screen to Red
        cout << "\a";
    }
}

short ReadHowManyQuestions()
{
    short NumberOfQuestions;
    do
    {
        cout << "How Many Questions do you want to answer ? ";
        cin >> NumberOfQuestions;
    } while (NumberOfQuestions < 1 || NumberOfQuestions >10);
    return NumberOfQuestions;
}

enQuestionsLevel ReadQuestionsLevel()
{
    short QuestionLevel = 0;
    do
    {
        cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
            cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel > 4);
    return (enQuestionsLevel)QuestionLevel;
}

enOperationType ReadOpType()
{
    short OpType;
    do
    {
        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
            cin >> OpType;
    } while (OpType < 1 || OpType > 5);
    return (enOperationType)OpType;
}

struct stQuestion
{
    int Number1 = 0;
    int Number2 = 0;
    enOperationType OperationType;
    enQuestionsLevel QuestionLevel;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};

struct stQuizz
{
    stQuestion QuestionList[100];
    short NumberOfQuestions;
    enQuestionsLevel QuestionsLevel;
    enOperationType OpType;
    short NumberOfWrongAnswers = 0;
    short NumberOfRightAnswers = 0;
    bool isPass = false;
};

int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Sub:
        return Number1 - Number2;
    case enOperationType::Mult:
        return Number1 * Number2;
    case enOperationType::Div:
        return Number1 / Number2;
    default:
        return Number1 + Number2;
    }
}

enOperationType GetRandomOperationType()
{
    int Op = RandomNumber(1, 4);
    return (enOperationType)Op;
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel, enOperationType OpType)
{
    stQuestion Question;

    if (QuestionLevel == enQuestionsLevel::Mix)
    {
        QuestionLevel = (enQuestionsLevel)RandomNumber(1, 3);
    }
    if (OpType == enOperationType::MixOp)
    {
        OpType = GetRandomOperationType();
    }
    Question.OperationType = OpType;

    switch (QuestionLevel)
    {
    case enQuestionsLevel::EasyLevel:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2,Question.OperationType);
        Question.QuestionLevel = QuestionLevel;
        return Question;

    case enQuestionsLevel::MedLevel:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2,Question.OperationType);
        Question.QuestionLevel = QuestionLevel;
        return Question;

    case enQuestionsLevel::HardLevel:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2,Question.OperationType);
        Question.QuestionLevel = QuestionLevel;
        return Question;
    }
    return Question;
}

void GenerateQuizzQuestions(stQuizz& Quizz)
{
    for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
    {
        Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OpType);
    }
}

int ReadQuestionAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}

void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber)
{
    cout << "\n";
    cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "] \n\n";
    cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
    cout << Quizz.QuestionList[QuestionNumber].Number2 << " ";
    cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OperationType);
    cout << "\n_________" << endl;
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{
    if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
    {
        Quizz.QuestionList[QuestionNumber].AnswerResult = false;
        Quizz.NumberOfWrongAnswers++;
        cout << "Worng Answer :-( \n";
        cout << "The right answer is: ";
        cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer;
        cout << "\n";
    }
    else
    {
        Quizz.QuestionList[QuestionNumber].AnswerResult = true;
        Quizz.NumberOfRightAnswers++;
        cout << "Right Answer :-) \n";
    }
    cout << endl;
    SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz)
{
    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
    {
        PrintTheQuestion(Quizz, QuestionNumber);
         Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(Quizz, QuestionNumber);
    }
    Quizz.isPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}

string GetFinalResultsText(bool Pass)
{
    if (Pass)
        return "PASS :-)";
    else
        return "Fail :-(";
}

void PrintQuizzResults(stQuizz Quizz)
{
    cout << "\n";
    cout << "______________________________\n\n";
    cout << " Final Resutls is " << GetFinalResultsText(Quizz.isPass);
    cout << "\n______________________________\n\n";
    cout << "Number of Questions: " << Quizz.NumberOfQuestions << endl;
    cout << "Questions Level : " << GetQuestionLevelText(Quizz.QuestionsLevel) << endl;
    cout << "OpType : " << GetOpTypeSymbol(Quizz.OpType) << endl;
    cout << "Number of Right Answers: " <<
        Quizz.NumberOfRightAnswers << endl;
    cout << "Number of Wrong Answers: " <<
        Quizz.NumberOfWrongAnswers << endl;
    cout << "______________________________\n";
}

void PlayMathGame()
{
    stQuizz Quizz;
    Quizz.NumberOfQuestions = ReadHowManyQuestions();
    Quizz.QuestionsLevel = ReadQuestionsLevel();
    Quizz.OpType = ReadOpType();
    GenerateQuizzQuestions(Quizz);
    AskAndCorrectQuestionListAnswers(Quizz);
    PrintQuizzResults(Quizz);
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        PlayMathGame();
        cout << endl << "Do you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}


int main()
{
    srand((unsigned)time(NULL));
     
    StartGame();

    return 0;
}



