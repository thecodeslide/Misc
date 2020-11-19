/****************************************************************************
 * dictionary.c
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

// create hash table and initialise all values to NULL
node* hashtable[500] = {NULL};

unsigned int count = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO // done
    char w[strlen(word)];
    for (uint8_t j = 0, k = strlen(word); j < k; j++)
    {
    	w[j] = tolower(word[j]);
    	if (j == k - 1)
    		w[k] = '\0';
    }
    
    uint16_t i = (hashme(w)); 
    
    // get hash of word from text and compare the words
    if (hashtable[i])
    {
    	node* c_node; 
    	// go to bucket containing hash
/*    	c_node = hashtable[i];*/
/*    		*/
/*    	// return true if word matches*/
/*    	if (strcmp(w, c_node->word) == 0)*/
/*    	{*/
/*    		return true;}*/
/*    	// word does not match, check next node*/
/*    	while (c_node->next != NULL)*/
/*    	{*/
/*    		c_node = c_node->next;*/
/*    		if (strcmp(w, c_node->word) == 0)*/
/*    		{*/
/*    			return true;}*/
/*    	}*/
		
		// go to bucket containing hash and return true if word matches
		for (c_node = hashtable[i]; c_node != NULL; c_node = c_node->next) 
		{	
			if (strcmp(w, c_node->word) == 0)
			{
    			return true;
    		}	
    	}		
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO // done
    // open file
    FILE* infile = fopen(dictionary, "r");
    
    if (infile)
    {
    	node* new_node = calloc(1, sizeof(node));
    	if (new_node == NULL)
        {
            unload();
            fclose(infile);
            return false;
        }
		// iterate over file
		while (fscanf(infile, "%s", new_node->word) != EOF)
    	{
			// hash the word to get index of bucket in hashtable
			uint16_t listIndex = (hashme(new_node->word));
			// inserting first node into empty list
			if (hashtable[listIndex] == NULL)
			{
				hashtable[listIndex] = new_node;
				count++;
			}
			// if list is not empty, insert at beginning
			else
			{
				new_node->next = hashtable[listIndex];
				hashtable[listIndex] = new_node;
				count++;
			}
			if (count > 0)
				new_node = (node*) calloc(1, sizeof(node));
				
		    if (new_node == NULL)
            {
                unload();
                fclose(infile);
                return false;
            }
    	}
    	// check whether there was an error
		if (ferror(infile))
		{
		    fclose(infile);
		    printf("Error reading %s.\n", dictionary);
		    return false;
		}
    	else if (feof(infile))
    	{
    		free(new_node);
    		new_node = NULL;
    		hashtable[499] = '\0';
    		fclose(infile);
    	}
    	return true;
    }
    perror("File opening failed");
    return false;
}

/**
 * Returns hash of word. taken from http://www.cse.yorku.ca/~oz/hash.html
 */
uint16_t hashme(const char *str)
{
        unsigned long hash = 5381;
        int c;

        while ((c = *str++))
            hash = ((hash << 5) + hash) ^ c; // hash * 33 + c 

        return (hash % 498);
}

/*uint32_t hashme(const char* word) */
/*{*/
/*	uint32_t hash = (toupper(word[0])-'A');*/
/*    return hash;*/
/*} */

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO // done
    if (count > 0)
    	return count;
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO // done
    bool unload = false;
    
    for (uint16_t i = 0; i < 500; i++)
    {	
        // iterate through hashtable and free linked nodes
/*        while(hashtable[i] != NULL)*/
/*        {*/
/*            node* cursor = hashtable[i];*/
/*            hashtable[i] = hashtable[i]->next;*/
/*            free(cursor);*/
/*            cursor = NULL;*/
/*        }*/
        for (node* cursor = hashtable[i]; cursor != NULL; cursor = hashtable[i])
        {
            hashtable[i] = hashtable[i]->next;
            free(cursor);
            cursor = NULL;
        }
		if (i == 499)
			return (unload = true);
    }
    return unload;
}

valgrind -v --show-reachable=yes --leak-check=full [more commands removed]

==8846== 
==8846== HEAP SUMMARY:
==8846==     in use at exit: 0 bytes in 0 blocks
==8846==   total heap usage: 143,094 allocs, 143,094 frees, 7,441,488 bytes allocated
==8846== 
==8846== All heap blocks were freed -- no leaks are possible
==8846== 
==8846== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
==8846== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)