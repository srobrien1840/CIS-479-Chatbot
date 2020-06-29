#include <iostream>
#include <vector>
#include <string>

using namespace std;
string to_upper(string input) {
	string result = "";
	for (int i = 0; i < input.size(); i++)
		result += toupper(input[i]);
	return result;
}

bool contains(string input, vector<string> find) {
	for (int i = 0; i < find.size(); i++)
	{
		if (input.find(find[i]) != string::npos) {
			return true;
		}
	}
	return false;
}

int main() {
	string breed = "Unknown";

	
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	cout << "                        Compact Rabbit Breed Classification Chatbot" << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;

	cout << endl << endl << endl;
	string input;

	cout << "Hi, I am the rabbit breed chatbot. Would You like me to help you classify a rabbit?" << endl << endl;
	getline(cin,input);
	input = to_upper(input);

	vector<string> yes = { "YES","YEAH","Y","SURE","WHY NOT","PLEASE","OK", "FINE", "COURSE", "ABSOLUTELY", "CERTAINLY", "I THINK SO", "PROBABLY", "I GUESS", "GUESS SO", "LITTLE" };
	vector<string> no = { "NO","NAH","N"};

	bool moveOn = false;
	while (!moveOn) {
		//Check if the user wants to use the chat bot against the confirm dictionary
		if (contains(input, yes)) {
			moveOn = true;
			cout << endl << endl << "Great! Tell me about your rabbit's fur." << endl;
			getline(cin,input);
			input = to_upper(input);

			//Two possible types of fur we will check for with dictionary of adjectives for each
			vector<string> wool = { "WOOL","2","TWO","LONG", "INCHES" };
			vector<string> flyback = { "FLY","BACK","TWO","SHORT", "BRISTLE" };
			//If their response did not match any entry in the fur dictionaries
			while (!contains(input, wool) && !contains(input, flyback)) {
				cout << endl << endl << "Is the fur longer than 2 inches?" << endl;
				getline(cin, input);
				input = to_upper(input);
				//Check the confirm dictionary, if yes thean it is a wool fur type
				if (contains(input, yes)) {
					input = "WOOL";
				}
				//Check the reject dictionary, if yes thean it is a flyback fur type
				else if (contains(input, no)) {
					input = "FlYBACK";
				}
				else
					input = "";
			}
			//If their response matched an entry in the wool fur dictionaries
			if (contains(input, wool)) {

				cout << endl << endl << "Okay! Tell me about your rabbit's ears." << endl;
				getline(cin,input);
				input = to_upper(input);

				//Two possible types of ears we will check for with dictionary of adjectives for each
				vector<string> lop = { "LOP","FOLD","HANG","DROOP", "BENT", "BEND", "LOOSE", "DANGLE", "LIMP", "RELAX", "SAG", "SLOUCH", "WILT" };
				vector<string> erect = { "POINT","STIFF","TALL", "ERECT", "STAND", "UPRIGHT", "RIGID", "PERK", "RAISE", "UP"};

				//If their response did not match any entry in the ear dictionaries
				while (!contains(input, lop) && !contains(input, erect)) {
					cout << endl << endl << "Are the ears floppy?" << endl;
					getline(cin,input);
					input = to_upper(input);

					//Check the confirm dictionary, if yes thean it is a lop ear type
					if (contains(input, yes)) {
						input = "FLOP";
					}
					//Check the reject dictionary, if yes thean it is a erect ear type
					else if (contains(input, no)) {
						input = "ERECT";
					}
					else
						input = "";
				}
				//if their response matched an entry in the erect ear dictionaries 
				if (contains(input, erect)) {
					cout << endl << endl << "Okay! How many pounds does your rabbit weigh?" << endl;
					getline(cin,input);
					input = to_upper(input);

					//Two possible weight categories we will check for with dictionary of possibilities for each
					vector<string> small = { "0","1","2","3"};
					vector<string> large = { "4","5","6", "7", "8", "9"};

					//If their response did not match any entry in the weight dictionaries
					if (!contains(input, small) && !contains(input, large)) {
						cout << endl << endl << "Is it more than 3 pounds?" << endl;
						getline(cin,input);
						input = to_upper(input);

						//Check the confirm dictionary, if yes thean it is a large weight type
						if (contains(input, yes)) {
							breed = "Jersey Wooly";
						}
						//Check the reject dictionary, if yes thean it is a small weight type
						else if (contains(input, no)) {
							breed = "English Angora";
						}
						//If the user is un sure we will give them our best matches
						else
							breed = "English Angora or Jersey Wooly";
					}
					//if their response matched an entry in the small weight dictionaries 
					else if (contains(input, small)) {
						breed = "Jersey Wooly";
					}
					//if their response matched an entry in the large weight dictionaries 
					else if (contains(input, large)) {
						breed = "English Angora";
					}
					//If the user is un sure we will give them our best matches
					else
						breed = "English Angora or Jersey Wooly";
				}
				//if their response matched an entry in the erect ear dictionaries 
				else if (contains(input, lop)) {
					breed = "American Fuzzy Lop";
				}
			}
			//if their response matched an entry in the flyback dictionaries 
			else if (contains(input, flyback)) {
					
				cout << endl << endl << "Good! Is there a white marking from jaw to base of the ears that makes a triangle?" << endl;
				getline(cin,input);
				input = to_upper(input);

				//Check the confirm dictionary, if yes thean it is a Dutch type
				if (contains(input, yes)) {
					breed = "Dutch";
				}
				else {

					cout << endl << endl << "Okay! How many pounds does your rabbit weigh?" << endl;
					getline(cin,input);
					input = to_upper(input);

					//Two possible weight categories we will check for with dictionary of possibilities for each
					vector<string> small = { "0","1","2","3" };
					vector<string> large = { "4","5","6", "7", "8", "9" };

					//If their response did not match any entry in the weight dictionaries
					if (!contains(input, small) && !contains(input, large)) {
						cout << endl << endl << "Is it less than 3 pounds?" << endl;
						getline(cin,input);
						input = to_upper(input);

						//Check the confirm dictionary, if yes thean it is a small weight type
						if (contains(input, yes)) {
							input = "0";
						}
						else
							input = "4";

					}
					//if their response matched an entry in the small dictionary
					if (contains(input, small))
					{
						breed = "Polish";
					}
					//if their response matched an entry in the large dictionary
					else if (contains(input, large))
					{
						cout << endl << endl << "Now tell me more about the fur. What color is it?" << endl;
						getline(cin,input);
						input = to_upper(input);

						//4 possible fur color categories we will check for with dictionary of possibilities for each
						vector<string> havana = { "BLACK","BLUE","CHOCOLATE"};
						vector<string> silver = { "FAWN","SILVER" };
						vector<string> white = { "WHITE"};
						vector<string> brown = { "BROWN"};

						if (contains(input, brown))
						{
							//Two types can be brown, one is light the other is dark
							cout << endl << endl << "Is it dark brown?" << endl;
							getline(cin,input);
							input = to_upper(input);

							//Check the confirm dictionary, if yes thean it is a havana type
							if (contains(input, yes)) {
								input = "CHOCOLATE";
							}
						}
						//if their response matched an entry in the Havana dictionary
						if (contains(input, havana)) {
							breed = "Havana";
						}
						//if their response matched an entry in the Silver dictionary
						else if (contains(input, silver)) {
							breed = "Silver";
						}
						//if their response matched an entry in the White dictionary
						else if (contains(input, white)) {
							breed = "Florida White";
						}
						//if their response matched no entry in the dictionaries
						else {
							breed = "Unknown";
						}
					}
				}
			}
		}
		//Check if the user wants to use the chat bot against the reject dictionary
		else if (contains(input, no))
		{
			cout << "Goodbye";
			return 0;
		}
		else
		{
			//The respose was not in either dictionary
			cout << "I'm sorry I don't understand. Can you tell me more?";
			getline(cin,input);
			input = to_upper(input);
		}
	}

		
	cout << endl << endl << "The rabbit breed that best described is the " << breed << endl << endl << endl;

	

	system("pause");
	return 0;
}