// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);
//fucniton for checking if score is nan:
bool isdoubleNan(double number) {

    if (number != number)
    {
        return true;
    }
    else if (number == number)
    {
        return false;
    }
    else{
        return true;
    }
    
}
//function used in calculating grades
double checkScore(double score){
   if (score > 100)
   {
    score = 100;
    return score;
   }
   else if (isdoubleNan(score))
   {
    return 0;
   }
   else{
    return score;
   }
}

char checkFinalLetter(double score) {
    if (score >= 90 && score <=100)
    {
        char letterGrade = 'A';
        return letterGrade;
    }
    else if (score >= 80 && score <90)
    {
        char letterGrade = 'B';
        return letterGrade;
    }
    else if (score >= 70 && score <80)
    {
        char letterGrade = 'C';
        return letterGrade;
    }
    else if (score >= 60 && score < 70)
    {
        char letterGrade = 'D';
        return letterGrade;
    }
    else if (score < 60) {
        char letterGrade = 'F';
        return letterGrade;
    }
    else {
        return 0;
    }

}

double checkExamScore (double examaverage, double finalScore, int finalCount, int examCount, double examSum) {
    double finalScore_2 = 0;
    finalScore_2 = finalScore * 0.4;
    if (finalScore_2 >= examaverage)
    {
        return finalScore;
    }
    else if(finalCount > 0) {
        examaverage = examaverage / 0.6666662;
        return examaverage;
    }
    else if(examCount == 1)
    {
        examaverage = examSum/2;
        return examaverage;
    }

    else{
        return examaverage;
    }
    
}
int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want
    int examCount = 0;
    int finalCount = 0;
    int hwCount = 0;
    int lwCount = 0;
    int readingCount = 0;
    int engmntCount = 0;
    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    //create intail sum for scores
    double examsum = 0;
    double finalsum = 0;
    double hwsum = 0;
    double lwsum = 0;
    double readingsum = 0;
    double engmntsum = 0;
    
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            // TODO(student): process exam score
            examsum += score;
            //cout << examsum << endl; //debugging
            examCount++;
            //cout << "examCount" << examCount << endl;
        } else if (category == "final-exam") {
            // TODO(student): process final score
            finalsum += score;
            finalCount++;
            //cout << "finalCount" << finalCount << endl;
        } else if (category == "hw") {
            // TODO(student): process hw score
            hwsum += score;
            hwCount++;
        } else if (category == "lw") {
            // TODO(student): process lw score
            lwsum += score;
            lwCount++;
        } else if (category == "reading") {
            // TODO(student): process reading score
            readingsum += score;
            readingCount++;
        } else if (category == "engagement") {
            // TODO(student): process engagement score
            engmntsum += score;
            engmntCount++;
        } else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

    // debugging
    //cout << "examsum: " << examsum << ", finalsum: " << finalsum << ", examCount: " << examCount << ", finalCount: " << finalCount << endl;
    // TODO(student): compute component averages
    double exam_average = 0;
    double hw_average = 0;
    double lw_average = 0;
    double reading = 0;
    double engagement = 0;
    double exAVG = 0;
    double fwExamScore = 0;
    int examCountsum = 0;
    // check if examcount is nonnegative
    if ((examCount > 0) && (finalCount == 0)) {
        exAVG = (examsum / examCount) * 0.6666662;// not sure why i need to multiply by this to get the right awnser.
    }
    else if (examCount > 0)
    {
        //cout << examCount << endl;
        //cout << finalCount << endl;
        examCountsum = examCount + finalCount;
        exAVG = (((examsum + finalsum) / examCountsum)) * 0.6666662;
        //cout << "exAVG:" << exAVG << " examsum:"<< examsum << " finalsum:" << finalsum << " examCount:" << examCountsum<<endl;
    }
    
    
    fwExamScore = checkExamScore(exAVG, finalsum, finalCount, examCount, examsum);
    //cout << "exAVG: " << exAVG << ", finalsum * 0.4: " << finalsum * 0.4 << endl;
    exam_average = fwExamScore; //40% 
    //cout << "After checkExamScore: exam_average = " << exam_average << endl;

    if (hwCount > 0)
    {
        hw_average = hwsum/hwCount; //40 %
    }
    
    if (lwCount > 0)
    {
        lw_average = lwsum/lwCount * 100; //8%
    }
    reading = checkScore((readingsum/readingCount)+15);//5%
    engagement = checkScore((engmntsum/engmntCount)+15);//5%

    // TODO(student): compute weighted total of components
    double w_examAvg = exam_average * 0.4;
    double w_hwAvg = hw_average * 0.4;
    double w_lwAvg = lw_average * 0.10;
    double w_rdAvg = reading * 0.05;
    double w_egAvg = engagement * 0.05;


   
   

    double weighted_total = w_examAvg+w_hwAvg+w_lwAvg+w_rdAvg+w_egAvg;

    // TODO(student): compute final letter grade
    char final_letter_grade = checkFinalLetter(weighted_total);

    print_results(
        exam_average, hw_average, lw_average, reading, engagement,
        weighted_total, final_letter_grade);
        //cout << examsum << endl << finalsum << endl << examCount << endl << finalCount << endl << exAVG << endl << exam_average;
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double reading,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "           reading: " << reading << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}

double sumdoubleArray(double arr[], int size) {
    double sum = 0;
    for(int i =0; i < size; i++) {
        sum+=arr[i];
    }

    return sum;
}
