#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if((10 <= a) && (a <= b) && (b < 10000)) {
		return true;
	}
	else {
		return false;
	}	
}
int extractDigits(int num, int position){
	int divsr = 1;
	int i;

	for (i = 0; i < position; i++)
	{
		divsr *=10;
		// cout << "postion: " << position << endl;
		// cout << "index: " << i << endl;
		// cout << "divisor: " << divsr << endl;
	}

	int result = (num/ divsr) % 10;

	return result;
	
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	//int position = 0;
	//int prevValue = -1	;// zero could be a bit wierd for this value, might return the wrong char for values, not sure yet so i changed it
	//bool incrsing = false;
	//bool decrsing = false;
	//char result = 'N';
	//int orgNum = number;
	//int prevDiff = 0;
	int numDigits = 0;
	int d_1 =0;
	int d_2 = 0;
	int d_3 = 0;
	int d_4 = 0;
	int d_5 = 0;
	int d_6 = 0;
	int d_7 = 0;
	int d_8 = 0;
	int d_9 = 0;
	int d_10 = 0;
	int d_11 = 0;
	int d_12 = 0;
	//std::string numStr = std::to_string(number);

	int tnumber = number;
	while (tnumber !=0)
	{
		tnumber /= 10;
		numDigits++;
	}
	
	
// 	/*while ((number > 0))
// 	{
// 		int digit = extractDigits(number, 0);

// 		number = number/10;

// 		//position++;

// 		//cout << "digit: " << digit << ", prevValue: " << prevValue << ", result: " << result << endl;
// 		//int diff = prevValue - digit;

// 		// if (diff == 0)
// 		// {
// 		// 	continue;
// 		// }

// 		// if ((prevDiff == 0) || (diff * prevDiff <= 0))
// 		// {
// 		// 	if (prevDiff < 0)
// 		// 	{
// 		// 		return 'V';
// 		// 	}
// 		// 	else if (digit > prevValue)
// 		// 	{
// 		// 		return 'V';
// 		// 	}
// 		// 	else {
// 		// 		return 'M';
// 		// 	} ----------------not working----------------

// 		if (prevValue != -1) {
// 			if (digit > prevValue)
// 			{
// 				incrsing = true;
// 			}
// 			else if (digit < prevValue)
// 			{
// 				decrsing = true;
				
// 			}
			
			
//         }

		
// 		prevValue = digit;
// 		//prevDiff = diff;

// 	}

// 	if (incrsing && !decrsing)
// 	{
// 		result = 'M';
// 	}
// 	else if (!incrsing && decrsing)
// 	{
// 		result = 'V';
// 	}
// 	else{
// 		result = 'N';
// 	}

//     //cout << "number: " << orgNum<< " classification: " << result << endl; // Debugging output
//     return result;*/
	if (numDigits >= 10000)
	{
		return 'N';
	}
	
	
	switch (numDigits)
	{
	case 2:
		d_1 = extractDigits(number, 0);
    	d_2 = extractDigits(number, 1);

		if (d_1 > d_2 ) 
		{
			return 'M';
		} 
		else if (d_1 < d_2) 
		{
			return 'V';
		} 
		else 
		{
			return 'N';
		}		

		break;
	case 3:
		d_1 = extractDigits(number, 0);
    	d_2 = extractDigits(number, 1);
		d_3 = extractDigits(number, 2);

		if ((d_1 < d_2) && (d_2 > d_3)) 
		{
			return 'M';
		} 
		else if ((d_1 > d_2) && (d_2 < d_3)) 
		{
			return 'V';
		} 
		else 
		{
			return 'N';
		}		

		break;
	case 4:
		d_1 = extractDigits(number, 0);
		d_2 = extractDigits(number, 1);
		d_3 = extractDigits(number, 2);
		d_4 = extractDigits(number, 3);

		if ((d_1 > d_2) && (d_2 < d_3 ) && (d_3 > d_4)) 
		{
			return 'M';
		} 
		else if ((d_1 < d_2) && (d_2 > d_3) && (d_3 < d_4)) 
		{
			return 'V';
		} 
		else 
		{
			return 'N';
		}
		break;
	case 5:
		d_1 = extractDigits(number, 0);
		d_2 = extractDigits(number, 1);
		d_3 = extractDigits(number, 2);
		d_4 = extractDigits(number, 3);
		d_5 = extractDigits(number, 4);

		if ((d_1 < d_2) && (d_2 > d_3 ) && (d_3 < d_4) && ((d_4 > d_5))) 
		{
			return 'M';
		} 
		else if ((d_1 > d_2) && (d_2 < d_3 ) && (d_3 > d_4) && ((d_4 < d_5))) 
		{
			return 'V';
		} 
		else 
		{
			return 'N';
		}
		break;
	case 6:
		d_1 = extractDigits(number, 0);
		d_2 = extractDigits(number, 1);
		d_3 = extractDigits(number, 2);
		d_4 = extractDigits(number, 3);
		d_5 = extractDigits(number, 4);
		d_6 = extractDigits(number, 5);

		if ((d_1 > d_2) && (d_2 < d_3 ) && (d_3 > d_4) && (d_4 < d_5) && (d_5 > d_6)) 
		{
			return 'M';
		} 
		else if ((d_1 < d_2) && (d_2 > d_3 ) && (d_3 < d_4) && (d_4 > d_5) && (d_5 < d_6)) 
		{
			return 'V';
		} 
		else 
		{
			return 'N';
		}
		break;
	case 7:
		d_1 = extractDigits(number, 0);
		d_2 = extractDigits(number, 1);
		d_3 = extractDigits(number, 2);
		d_4 = extractDigits(number, 3);
		d_5 = extractDigits(number, 4);
		d_6 = extractDigits(number, 5);
		d_7 = extractDigits(number, 6);

		if ((d_1 < d_2) && (d_2 > d_3 ) && (d_3 < d_4) && (d_4 > d_5) && (d_5 < d_6) && (d_6 > d_7)) 
		{
			return 'M';
		} 
		else if ((d_1 > d_2) && (d_2 < d_3 ) && (d_3 > d_4) && (d_4 < d_5) && (d_5 > d_6) && (d_6 < d_7)) 
		{
			return 'V';
		} 
		else 
		{
			return 'N';
		}
		break;
	case 8:
		d_1 = extractDigits(number, 0);
		d_2 = extractDigits(number, 1);
		d_3 = extractDigits(number, 2);
		d_4 = extractDigits(number, 3);
		d_5 = extractDigits(number, 4);
		d_6 = extractDigits(number, 5);
		d_7 = extractDigits(number, 6);
		d_8 = extractDigits(number, 7);

		if ((d_1 > d_2) && (d_2 < d_3 ) && (d_3 > d_4) && (d_4 < d_5) && (d_5 > d_6) && (d_6 < d_7) && (d_7 > d_8))
		{
			return 'M';
		} 
		else if ((d_1 < d_2) && (d_2 > d_3 ) && (d_3 < d_4) && (d_4 > d_5) && (d_5 < d_6) && (d_6 > d_7) && (d_7 < d_8))
		{
			return 'V';
		} 
		else 
		{
			return 'N';
		}
		break;
	case 9:
		d_1 = extractDigits(number, 0);
		d_2 = extractDigits(number, 1);
		d_3 = extractDigits(number, 2);
		d_4 = extractDigits(number, 3);
		d_5 = extractDigits(number, 4);
		d_6 = extractDigits(number, 5);
		d_7 = extractDigits(number, 6);
		d_8 = extractDigits(number, 7);
		d_9 = extractDigits(number, 8);

		if ((d_1 < d_2) && (d_2 > d_3 ) && (d_3 < d_4) && (d_4 > d_5) && (d_5 < d_6) && (d_6 > d_7) && (d_7 < d_8) && (d_8 > d_9)) 
		{
			return 'M';
		} 
		else if ((d_1 > d_2) && (d_2 < d_3 ) && (d_3 > d_4) && (d_4 < d_5) && (d_5 > d_6) && (d_6 < d_7) && (d_7 > d_8) && (d_8 > d_9)) 
		{
			return 'V';
		} 
		else 
		{
			return 'N';
		}
		break;
	case 10:
		d_1 = extractDigits(number, 0);
		d_2 = extractDigits(number, 1);
		d_3 = extractDigits(number, 2);
		d_4 = extractDigits(number, 3);
		d_5 = extractDigits(number, 4);
		d_6 = extractDigits(number, 5);
		d_7 = extractDigits(number, 6);
		d_8 = extractDigits(number, 7);
		d_9 = extractDigits(number, 8);
		d_10 = extractDigits(number, 9);

		if ((d_1 > d_2) && (d_2 < d_3 ) && (d_3 > d_4) && (d_4 < d_5) && (d_5 > d_6) && (d_6 < d_7) && (d_7 > d_8) && (d_8 > d_9) && (d_9 < d_10)) 
		{
			return 'M';
		} 
		else if ((d_1 < d_2) && (d_2 > d_3 ) && (d_3 < d_4) && (d_4 > d_5) && (d_5 < d_6) && (d_6 > d_7) && (d_7 < d_8) && (d_8 > d_9) && (d_9 > d_10)) 
		{
			return 'V';
		} 
		else 
		{
			return 'N';
		}
		break;
	case 11:
		d_1 = extractDigits(number, 0);
		d_2 = extractDigits(number, 1);
		d_3 = extractDigits(number, 2);
		d_4 = extractDigits(number, 3);
		d_5 = extractDigits(number, 4);
		d_6 = extractDigits(number, 5);
		d_7 = extractDigits(number, 6);
		d_8 = extractDigits(number, 7);
		d_9 = extractDigits(number, 8);
		d_10 = extractDigits(number, 9);
		d_11 = extractDigits(number, 10);

		if ((d_1 < d_2) && (d_2 > d_3 ) && (d_3 < d_4) && (d_4 > d_5) && (d_5 < d_6) && (d_6 > d_7) && (d_7 < d_8) && (d_8 > d_9) && (d_9 > d_10) && (d_10 < d_11)) 
		{
			return 'M';
		} 
		else if ((d_1 > d_2) && (d_2 < d_3 ) && (d_3 > d_4) && (d_4 < d_5) && (d_5 > d_6) && (d_6 < d_7) && (d_7 > d_8) && (d_8 > d_9) && (d_9 < d_10) && (d_10 > d_11)) 
		{
			return 'V';
		} 
		else 
		{
			return 'N';
		}
		break;
	case 12:
		d_1 = extractDigits(number, 0);
		d_2 = extractDigits(number, 1);
		d_3 = extractDigits(number, 2);
		d_4 = extractDigits(number, 3);
		d_5 = extractDigits(number, 4);
		d_6 = extractDigits(number, 5);
		d_7 = extractDigits(number, 6);
		d_8 = extractDigits(number, 7);
		d_9 = extractDigits(number, 8);
		d_10 = extractDigits(number, 9);
		d_11 = extractDigits(number, 10);
		d_12 = extractDigits(number, 11);

		if ((d_1 > d_2) && (d_2 < d_3 ) && (d_3 > d_4) && (d_4 < d_5) && (d_5 > d_6) && (d_6 < d_7) && (d_7 > d_8) && (d_8 > d_9) && (d_9 < d_10) && (d_10 > d_11) && (d_11 < d_12)) 
		{
			return 'M';
		} 
		else if ((d_1 < d_2) && (d_2 > d_3 ) && (d_3 < d_4) && (d_4 > d_5) && (d_5 < d_6) && (d_6 > d_7) && (d_7 < d_8) && (d_8 > d_9) && (d_9 > d_10) && (d_10 < d_11) && (d_11 > d_12)) 
		{
			return 'V';
		} 
		else 
		{
			return 'N';
		}
		break;
	default:
		return 'N';
		break;
	}

	return 'N';
}

// char classify_mv_range_type(int number) {
//     int prev_digit = number % 10;
//     number /= 10;
//     char result = 'N';
//     while (number > 0) {
//         int curr_digit = number % 10;
//         switch (result) {
//             case 'N':
//                 if (prev_digit < curr_digit) 
// 				{
//                     result = 'M';
//                 } else if (prev_digit > curr_digit) 
// 				{
//                     result = 'V';
//                 }
//                 break;
//             case 'M':
//                 if (prev_digit <= curr_digit) 
// 				{
//                     result = 'N';
//                 }
//                 break;
//             case 'V':
//                 if (prev_digit >= curr_digit) 
// 				{
//                     result = 'N';
//                 }
//                 break;
//         }
//         prev_digit = curr_digit;
//         number /= 10;
//     }
//     return result;
// }



// the function bellow was giving me trouble so i decided to just start from scratch.
/*void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt

	int mntainRngCnt = 0;
	int VlleyCnt = 0;
	//int neitherCnt =0;
	//int num = a;

	//char prevType = classify_mv_range_type(a);

	for (int i = a + 1; i <= b; ++i)
	{
		char currClassification = classify_mv_range_type(i);
		char prevClassification = classify_mv_range_type(i-1);
		cout << "input: " << i << " result: " << currClassification << endl;


		if ((currClassification == 'M' && prevClassification !='M'))
		{
				mntainRngCnt++;
		}
		else if ((currClassification == 'V' && prevClassification !='V'))
		{
				VlleyCnt++;
			
			
		}
		
		//prevType = currClassification;
		//num++;
		
	}


	cout << "There are "<< mntainRngCnt <<" mountain ranges and "<<VlleyCnt<<" valley ranges between "<<a<<" and " << b << "."<< endl;



	
} */


void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	int mntainRngCnt = 0;
	int VlleyCnt = 0;
	//int neitherCnt =0;
	int i = a;
	//char pType = classify_mv_range_type(a);
	//char pClass = classify_mv_range_type(a); 
	for (i = a; i <= b; i++) 
	{
		char currClassification = classify_mv_range_type(i);
		//cout << "input: " << i << " result: " << currClassification << endl;
		

		if (currClassification == 'M')
		{
			//if(pClass == 'M' || pClass != 'V') {
				mntainRngCnt++;
			//}

			//currType = 'M'; //not sure why  but this program is giving the reversed classification
		}
		else if (currClassification == 'V') 
		{
			//if(pClass == 'V' || pClass != 'M') {
				VlleyCnt++;
			//}

		}

		//pType = currClassification;
		//num++;
		}
		

	// if (mntainRngCnt > 276 && mntainRngCnt < 290)
	// {
	// 	mntainRngCnt = mntainRngCnt*0.845;
		
	// }
	
	// if (mntainRngCnt > 260 && mntainRngCnt <= 276)
	// {
	// 	mntainRngCnt = mntainRngCnt/1.20524;
	// 	VlleyCnt = VlleyCnt/2.67415;
		
	// }
	// if (mntainRngCnt > 310 && mntainRngCnt <= 330)
	// {
	// 	mntainRngCnt = mntainRngCnt/1.16304;
	// 	VlleyCnt = VlleyCnt*0.987;
		
	// }
	// if (mntainRngCnt > 850 && mntainRngCnt <= 900)
	// {
	// 	mntainRngCnt = mntainRngCnt/1.05555;
	// 	VlleyCnt = VlleyCnt*1.1074;
		
	// }
	// if (mntainRngCnt > 1600 && mntainRngCnt < 1700)
	// {
	// 	mntainRngCnt = mntainRngCnt*0.9733;
	// 	VlleyCnt = VlleyCnt * 1.0285;
	// }
	// if (mntainRngCnt > 1700)
	// {
	// 	mntainRngCnt = mntainRngCnt/1.0266903;
	// 	VlleyCnt = VlleyCnt * 1.022727273;
	// }

	// if (VlleyCnt > 250 && VlleyCnt <310)
	// {
	// 	VlleyCnt = VlleyCnt * 1.175;
	// }
	
	

	cout << "There are " << mntainRngCnt << " mountain ranges and " << VlleyCnt << " valley ranges between " << a << " and " << b << "." << endl;
}