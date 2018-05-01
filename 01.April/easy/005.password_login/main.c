#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#define FICHERO "pass.safe"

void main(void){

	FILE *seguridad;

	int i;
	int loginDone=0, loginFail=0;
	char user[20];
	char *password;

	char users[20];
	char passwords[20];

	while(!loginDone){

		if(!loginFail)
			printf("Wellcome\nUser: ");
		else
			printf("\n\aInvalid user/pass.\nUser: ");

		scanf("%s", &user);
		password = getpass("Password: ");

		//printf("\n%s\n %s\n", user, password);


		seguridad = fopen(FICHERO,"r");
		if(seguridad == NULL){
			printf("File not created, errno: %d\n", errno);
			return;
		}

		char buf[100];
		char ch;
		while(fgets(buf, sizeof buf, seguridad) != NULL){
			sscanf( buf, "%[^:]:%s %s", &users, &passwords);
			if(!strcmp(user,users))
				if(!strcmp(password,passwords)){
					printf("%s@pc:~/$ ", user);
					//scanf("%c", &ch);
					while( getchar() != '\n');
					getchar();
					loginDone = 1;
				}
		}
		loginFail=1;
	}
}
