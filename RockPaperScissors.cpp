#include "RockPaperScissors.h"

int RockPaperScissors::play(int rounds, cartesian::Cartesian* cartesian, bool print_flag)
{
	int opponent_move, ai_move, last_opponent_points, last_opponent_move, last_ai_move;
	int ai_score = 0, opponent_score = 0, last_ai_score = 0, last_opponent_score = 0;
	vector<double> res;
	vector<double> input;
	std::string ai_move_string, opponent_move_string;

	if (print_flag) {
		cout << "Playing against: " << this->strategy->getName() << endl;
		cout << "AI player----------Strategy" << endl;
		cout << "---------------------------" << endl;
	}

	for (int i = 0; i < rounds; i++) { //igraj broj rundi
		if (i == 0) {
			int tmp;
			if (this->strategy->getName() == "Tit for Tat") {
				last_opponent_move = opponent_move = this->strategy->getFirstMove();
				tmp = rand() % 3;
			}
			else {
				last_opponent_move = opponent_move = this->strategy->getNextMove();
				if (this->strategy->getName() == "Only Rock") tmp = 1;
				if (this->strategy->getName() == "Only Paper") tmp = 2;
				if (this->strategy->getName() == "Only Scissors") tmp = 0;
				else tmp = rand() % 3;
			}
			
			input.push_back(tmp);
			input.push_back(last_opponent_move);
			if (tmp == last_opponent_move) {
				input.push_back(1);
			}
			else if (tmp == 0 && last_opponent_move == 1) {
				input.push_back(0);
			}
			else if (tmp == 0 && last_opponent_move == 2) {
				input.push_back(3);
			}
			else if (tmp == 1 && last_opponent_move == 0) {
				input.push_back(3);
			}
			else if (tmp == 1 && last_opponent_move == 2) {
				input.push_back(0);
			}
			else if (tmp == 2 && last_opponent_move == 0) {
				input.push_back(0);
			}
			else if (tmp == 2 && last_opponent_move == 1) {
				input.push_back(3);
			}
		}

		else {
			if(this->strategy->getName() == "Tit for Tat") opponent_move = this->strategy->getNextMove(last_ai_move);
			else opponent_move = this->strategy->getNextMove();
			input.push_back(last_ai_move);
			input.push_back(last_opponent_move);
			input.push_back(last_ai_score);
		}

		cartesian->evaluate(input, res);

		if (res.back() >= -0.5 && res.back() <= 0.5) ai_move = 0;
		else if (res.back() < -0.5 && res.back() >= -1 || res.back() > 0.5 && res.back() <= 1) ai_move = 1;
		else if (res.back() < -1 || res.back() > 1) ai_move = 2;

		if (ai_move == opponent_move) {
			opponent_score++;
			ai_score++;
			last_ai_score = 1;
			last_opponent_points = 1;
		}

		else if (ai_move == 0 && opponent_move == 1) {
			opponent_score += 3;
			last_ai_score = 0;
			last_opponent_points = 3;
		}

		else if (ai_move == 0 && opponent_move == 2) {
			ai_score += 3;
			last_ai_score = 3;
			last_opponent_points = 0;
		}

		else if (ai_move == 1 && opponent_move == 0) {
			ai_score += 3;
			last_ai_score = 3;
			last_opponent_points = 0;
		}

		else if (ai_move == 1 && opponent_move == 2) {
			opponent_score += 3;
			last_ai_score = 0;
			last_opponent_points = 3;
		}

		else if (ai_move == 2 && opponent_move == 0) {
			opponent_score += 3;
			last_ai_score = 0;
			last_opponent_points = 3;
		}

		else if (ai_move == 2 && opponent_move == 1) {
			ai_score += 3;
			last_ai_score = 3;
			last_opponent_points = 0;
		}

		if (ai_move == 0) ai_move_string = "Rock";
		else if (ai_move == 1) ai_move_string = "Paper";
		else ai_move_string = "Scissors";
		if (opponent_move == 0) opponent_move_string = "Rock";
		else if (opponent_move == 1) opponent_move_string = "Paper";
		else opponent_move_string = "Scissors";

		last_ai_move = ai_move;
		last_opponent_move = opponent_move;
		input.clear();

		if (print_flag) {
			cout << ai_move_string << "             " << opponent_move_string << endl;;
		}
	}
	if (print_flag) {
		cout << "AI score: " << ai_score << endl;
		cout << "Strategy score: " << opponent_score << endl;
	}

    return ai_score;
}
