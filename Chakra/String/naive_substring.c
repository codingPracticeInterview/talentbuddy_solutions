/** Naive substring matching algorithm. 
 *  Given a text string of length N and pattern of length M, find pattern matches 
 *  and print the positions in text at which the pattern starts. 
 *
 *  Worst case complexity is O((N - M + 1)M).  
 *   
 *  Optimization: When pattern match is found, increment the text string index by  
 *  pattern length.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFERSIZE	100

void substring_match(char *text, char *pattern) {
	int t_len = 0, p_len = 0, tidx = 0, pidx = 0, pat_found = 0;
	
	t_len = strlen(text);
	p_len = strlen(pattern);
	
	if(t_len < p_len) {
		printf("Size of Pattern String greater than Text String\n");
		return;
	}
	
	for(tidx = 0; tidx <= (t_len - p_len); tidx++) {
		for(pidx = 0; pidx < p_len; pidx++) {
			if(text[tidx+pidx] != pattern[pidx]) {
				break;
			}
		}
		
		if(pidx == p_len) {
			printf("Pattern '%s' found in text string at position %d\n", pattern, tidx+1);
			pat_found = 1;
			tidx += (p_len - 1);
		}
	}
	
	if(!pat_found) {
		printf("Pattern '%s' not found in text string '%s'\n", pattern, text);
	}
}

int main() {
	char *text = NULL, *pattern = NULL;
	size_t in_bytes = 0, b_read = 0;
	
	printf("Input Text String\n");
	b_read = getline(&text, &in_bytes, stdin);
	if(text[b_read - 1] == '\n') {
		text[b_read - 1] = '\0';
	}
	
	printf("Input Pattern String\n");
	b_read = getline(&pattern, &in_bytes, stdin);
	if(pattern[b_read - 1] == '\n') {
		pattern[b_read - 1] = '\0';
	}
	
	substring_match(text, pattern);
	
	return 0;
}
	
	