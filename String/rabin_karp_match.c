#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFERSIZE	100
#define BASE		128
#define PRIME		37

void rabin_karp_match(char *txt, char *pat, unsigned int base, 
			unsigned int prime)
{
	unsigned int t_len, p_len, t_idx, p_idx, pat_found = 0;
	int hash_txt = 0, /* Rolling Hash of txt string of size p_len */  
		hash_pat = 0, /* Hash of Pattern string */
		h = 1;   /* base ^ (p_len - 1) */
		
	t_len = strlen(txt);
	p_len = strlen(pat);
	
	/* Calculate h = base ^ (p_len - 1) */
	for (p_idx = 0; p_idx < (p_len - 1); p_idx++) {
		h = (h * base) % prime;
	}
	
	/* Calculate hash of the entire pattern string and 
	 * hash of p_len txt string starting at index 0
	 */
	 for (p_idx = 0; p_idx < p_len; p_idx++) {
	 	hash_txt = (txt[p_idx] + base * hash_txt) % prime;
	 	hash_pat = (pat[p_idx] + base * hash_pat) % prime;
	 }
	 
	 printf("Hash txt: %d, Hash Pat: %d, H: %d\n", hash_txt, hash_pat, h);
	 
	 for (t_idx = 0; t_idx <= (t_len - p_len); t_idx++) {
	 	/* Check if the p_len character hash of txt string matches the hash of 
	 	 * pattern string. If there is a hash match, perform linear char by char 
	 	 * comparison to determine substring match.
	 	 */
	 	 if(hash_txt == hash_pat) {
	 	 	printf("Hash match @ %d!!\n", t_idx);
	 	 	for(p_idx = 0; p_idx < p_len; p_idx++) {
	 	 		if(txt[t_idx + p_idx] != pat[p_idx]) {
	 	 			break;
	 	 		}
	 	 	}
	 	 	
	 	 	if(p_idx == p_len) {
	 	 		printf("Pattern '%s' found in text string at position %d\n", pat, t_idx+1);
				pat_found = 1;
			}
		}
			
		/* Compute the p_len char hash of txt string starting at the next position */
		if(t_idx <(t_len - p_len)) {
			hash_txt = (hash_txt + prime - ((h*txt[t_idx])%prime)) % prime;
			hash_txt = (base * hash_txt + txt[t_idx + p_len]) % prime;
		 	printf("Next Hash txt: %d, Pos: %d\n", hash_txt, t_idx+1);
		}
	 }
	 
	 if(!pat_found) {
	 	printf("Pattern '%s' not found in text string '%s'\n", pat, txt);
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
	
	rabin_karp_match(text, pattern, BASE, PRIME);
	
	return 0;
}
	