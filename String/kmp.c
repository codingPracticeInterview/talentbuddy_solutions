#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *compute_failure_func(char *pattern, int len) {
	int prefix_len = 0, pat_idx;
	int *fail_func;
	
	fail_func = malloc(len * sizeof(int));
	
	if(!fail_func) {
		return NULL;
	}
	
	fail_func[0] = 0;
	
	for(pat_idx = 1; pat_idx < len; pat_idx++) {
		while (prefix_len > 0 && pattern[prefix_len] != pattern[pat_idx]) {
			prefix_len = fail_func[prefix_len - 1];
		}
		
		if(pattern[prefix_len] == pattern[pat_idx]) {
			 prefix_len++;
		}
		
		fail_func[pat_idx] =  prefix_len;
	}
	
	return fail_func;
}

void kmp_substring_search(char *txt, char *pattern) {
	int txt_len, pat_len;
	int *fail_func = NULL;
	int match_idx, txt_idx;
	
	pat_len = strlen(pattern);
	txt_len = strlen(txt);
	
	fail_func = compute_failure_func(pattern, pat_len);
	
	if(!fail_func) {
		printf("Memory Alloc Failure\n");
		return;
	}
	
	for(match_idx=0; match_idx < pat_len; match_idx++) {
		printf("fail_func[%d] -> %d\n",match_idx, fail_func[match_idx]);
	}
	
	match_idx = 0;
	
	for(txt_idx = 0; txt_idx <txt_len; txt_idx++) {
		while(match_idx > 0 && txt[txt_idx] != pattern[match_idx]) {
			match_idx = fail_func[match_idx - 1];
		}
		
		if(txt[txt_idx] == pattern[match_idx]) {
			match_idx++;
		}
		
		if(match_idx == pat_len) {
			printf("Pattern '%s' found in text string at position %d\n", pattern, (txt_idx - match_idx + 1));
			match_idx = fail_func[match_idx - 1];
		}
	}
	
	free(fail_func);
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
    
    kmp_substring_search(text, pattern);
	
	return 0;
}
