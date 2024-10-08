#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Journal {
    char judul[100];
    char penulis[100];
    char afiliasi[100];
    char email[100];
    char abstrak[1000];
    char kata_kunci[100];
};

int countWords(char *str);
int isEmailValid(char email[]);
void inputTitle(char *judul);
void inputAuthors(char *author);
void inputAffiliation(char *afiliasi);
void inputEmail(char *email);
void inputAbstract(char *abstract);
void inputKeywords(char *keyword);

int main() {
    struct Journal journal;
    char hasil[2000] = "";

    inputTitle(journal.judul);
    inputAuthors(journal.penulis);
    inputAffiliation(journal.afiliasi);
    inputEmail(journal.email);
    inputAbstract(journal.abstrak);
    inputKeywords(journal.kata_kunci);

    strcat(hasil, journal.judul);
    strcat(hasil, "\n\n");
    strcat(hasil, journal.penulis);
    strcat(hasil, "\n");
    strcat(hasil, journal.afiliasi);
    strcat(hasil, "\n");
    strcat(hasil, journal.email);
    strcat(hasil, "\n\n");
    strcat(hasil, journal.abstrak);
    strcat(hasil, "\n\nKata Kunci: ");
    strcat(hasil, journal.kata_kunci);

    system("cls");
    printf("%s", hasil);

    return 0;
}

int countWords(char *str) {
    int count = 0;
    char temp[1000];
    strcpy(temp, str);

    char *token = strtok(temp, " ");
    
    while (token != NULL) {
        count++;                    
        token = strtok(NULL, " ");  
    }
    
    return count;
}

int isEmailValid(char email[]){
	char domain[] = "@upnjatim.ac.id";
    if (strstr(email, domain) != NULL) 
        return 1;
    else
        return 0;
}

void inputTitle(char *judul){
	do{
		printf("Masukkan judul jurnal (5-14 kata): ");
		fgets(judul, 100, stdin);
		judul[strcspn(judul, "\n")] = '\0';
		
		if(countWords(judul) < 5 || countWords(judul) > 14)
			printf("Judul harus terdiri dari 5-14 kata!\n");
	}while(countWords(judul) < 5 || countWords(judul) > 14);
}

void inputAuthors(char *author){
	int authorCount = 0;
	do{
		printf("Masukkan nama penulis (maksimal 3 penulis, dipisahkan koma): ");
		fgets(author, 100, stdin);
		author[strcspn(author, "\n")] = '\0';
		
	    char temp[100];
	    strcpy(temp, author);
	    
	    char *token = strtok(temp, ",");
	    authorCount = 0;
	    
	    while (token != NULL) {
	        authorCount++;
	        token = strtok(NULL, ",");
	    }
	    
		if(authorCount > 3)
			printf("Penulis tidak boleh lebih dari 3 orang.\n");
	}while(authorCount > 3);
}

void inputAffiliation(char *afiliasi){
    printf("Masukkan afiliasi penulis: ");
    fgets(afiliasi, 100, stdin);
    afiliasi[strcspn(afiliasi, "\n")] = '\0';
}

void inputEmail(char *email){
	do{
		printf("Masukkan email penulis : ");
		fgets(email, 100, stdin);
		email[strcspn(email, "\n")] = '\0';
		
		if(!isEmailValid(email))
			printf("Email tidak valid, gunakan email UPN (@upnjatim.ac.id)!\n");
	}while(!isEmailValid(email));
}

void inputAbstract(char *abstract){
	do{
		printf("Masukkan abstrak jurnal (Maksimal 200 kata): ");
		fgets(abstract, 1000, stdin);
		abstract[strcspn(abstract, "\n")] = '\0';
		
		if(countWords(abstract) > 200)
			printf("Abstrak maksimal 200 kata!\n");
	}while(countWords(abstract) > 200);
}

void inputKeywords(char *keyword){
	char temp[100];
	int isError;
	do{
	    isError = 0;
	    
		printf("Masukkan kata kunci (3-5 kata, dipisahkan koma): ");
		fgets(keyword, 100, stdin);
		keyword[strcspn(keyword, "\n")] = '\0';
		
	    strcpy(temp, keyword);
	    char *token = strtok(temp, ",");
	    
	    while (token != NULL) {
	    	if(countWords(token) < 3 || countWords(token) > 5)
	    		isError = 1;
	    		
	        token = strtok(NULL, ",");
	    }
		
		if(isError)
			printf("Kata kunci harus memiliki 3-5 kata.\n");
	}while(isError);
}