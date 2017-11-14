#include <iterator>
#include <list>
#include <map>
#include <pthread.h>
#include <set>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/vfs.h>
#include <unistd.h>
#include <vector>

#include <regex>
#include <iostream>

int main()
{
	try {
const char *reg_esp1 = "{ ,.\\t\\n;:}"; // List of separator characters.
const char *reg_esp2 = "[.]"; // List of separator characters.

// this can be done using raw string literals:
// const char *reg_esp = R"([ ,.\t\n;:])";

std::regex rgx(reg_esp2); // 'regex' is an instance of the template class
                         // 'basic_regex' with argument of type 'char'.
std::cmatch match; // 'cmatch' is an instance of the template class
                   // 'match_results' with argument of type 'const char *'.
const char *target = "Unseen University - Ankh-Morpork";

// Identifies all words of 'target' separated by characters of 'reg_esp'.
if (std::regex_search(target, match, rgx)) {
	std::cout << "got here dude\n";
    // If words separated by specified characters are present.

    const size_t n = match.size();
    for (size_t a = 0; a < n; a++) {
        std::string str (match[a].first, match[a].second);
        std::cout << str << "\n";
    }
}
else std::cout << "no go\n";
}
catch (std::regex_error& e) {
	if (e.code() == std::regex_constants::error_backref)
		std::cerr << "backref dude";
	else if (e.code() == std::regex_constants::error_brack)
		std::cerr << "brack dude\n";
	else std::cerr << "Exception: " << e.code() << '\n';
}

}
