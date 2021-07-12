#include "PrisonersDilemma.h"

int PrisonersDilemma::play(int rounds, cartesian::Cartesian* cartesian, bool print_flag)
{
	int opponent_move, ai_move, last_opponent_points, last_opponent_move, last_ai_move, before_last_ai_move;
	int ai_score = 0, opponent_score = 0, last_ai_score = 0, last_opponent_score = 0;
	bool betrayed = false;
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
			last_opponent_move = opponent_move = this->strategy->getFirstMove(); 
			if (this->strategy->getName() == "Always Cooperate") tmp = 1;
			if (this->strategy->getName() == "Always Confess") tmp = 0;
			if (this->strategy->getName() == "Grudger") tmp = 1;
			if (this->strategy->getName() == "Tit For Tat") tmp = 1;
			if (this->strategy->getName() == "Pessimistic Tit For Tat") tmp = 0;
			if (this->strategy->getName() == "Pavlovian") tmp = 1;
			if (this->strategy->getName() == "Alternating") tmp = 0;
			if (this->strategy->getName() == "Tit For Two Tats") tmp = 1;
			if (this->strategy->getName() == "Random") tmp = 0;
			input.push_back(tmp);
			input.push_back(last_opponent_move);
			if (tmp == 0 && last_opponent_move == 0) {
				input.push_back(1);
			}

			else if (tmp == 0 && last_opponent_move == 1) {
				input.push_back(5);
			}

			else if (tmp == 1 && last_opponent_move == 0) {
				input.push_back(0);
			}

			else if (tmp == 1 && last_opponent_move == 1) {
				input.push_back(3);
			}
		}

		else if (i == 1) {
			if (this->strategy->getName() == "Grudger") opponent_move = this->strategy->getNextMove(betrayed);
			else if (this->strategy->getName() == "Tit For Tat" || this->strategy->getName() == "Pessimistic Tit For Tat")
				opponent_move = this->strategy->getNextMove(ai_move);
			else if (this->strategy->getName() == "Pavlovian") opponent_move = this->strategy->getNextMove(last_opponent_move, last_opponent_points);
			else if (this->strategy->getName() == "Alternating") opponent_move = this->strategy->getNextMove(last_opponent_move);
			else if (this->strategy->getName() == "Tit For Two Tats") opponent_move = this->strategy->getNextMove(last_ai_move, 1);
			else opponent_move = this->strategy->getNextMove();
			input.push_back(ai_move);
			input.push_back(last_opponent_move);
			input.push_back(last_ai_score);

		}

		else {
			if (this->strategy->getName() == "Grudger") opponent_move = this->strategy->getNextMove(betrayed);
			else if (this->strategy->getName() == "Tit For Tat" || this->strategy->getName() == "Pessimistic Tit For Tat") 
				opponent_move = this->strategy->getNextMove(ai_move);
			else if (this->strategy->getName() == "Pavlovian") opponent_move = this->strategy->getNextMove(last_opponent_move, last_opponent_points);
			else if (this->strategy->getName() == "Alternating") opponent_move = this->strategy->getNextMove(last_opponent_move);
			else if (this->strategy->getName() == "Tit For Two Tats") opponent_move = this->strategy->getNextMove(last_ai_move, before_last_ai_move);
			else opponent_move = this->strategy->getNextMove();
			input.push_back(ai_move);
			input.push_back(last_opponent_move);
			input.push_back(last_ai_score);
		}

		cartesian->evaluate(input, res);

		if (res.back() >= -1 && res.back() <= 1) ai_move = 0;
		else if (res.back() < -1 || res.back() > 1) ai_move = 1;

		if (ai_move == 0) betrayed = true;

		if (ai_move == 0 && opponent_move == 0) {
			ai_score++;
			opponent_score++;
			last_ai_score = 1;
			last_opponent_points = 1;
		}

		else if (ai_move == 0 && opponent_move == 1) {
			ai_score += 5;
			last_ai_score = 5;
			last_opponent_points = 0;
		}

		else if (ai_move == 1 && opponent_move == 0) {
			opponent_score += 5;
			last_ai_score = 0;
			last_opponent_points = 5;
		}

		else if (ai_move == 1 && opponent_move == 1) {
			ai_score += 3;
			opponent_score += 3;
			last_ai_score = 3;
			last_opponent_points = 3;
		}
		
		if (ai_move == 1) ai_move_string = "Cooperate";
		else ai_move_string = "Confess";
		if (opponent_move == 1) opponent_move_string = "Cooperate";
		else opponent_move_string = "Confess";

		if (i == 0) {
			last_ai_move = before_last_ai_move = ai_move;
		}
		else {
			before_last_ai_move = last_ai_move;
			last_ai_move = ai_move;
		}

		if (print_flag) {
			cout << ai_move_string << "             " << opponent_move_string << endl;
		}
		res.clear();
		input.clear();
		last_opponent_move = opponent_move;
	}
	if (print_flag) {
		cout << "AI score: " << ai_score << endl;
		cout << "Strategy score: " << opponent_score << endl;
	}

	return ai_score;
}
