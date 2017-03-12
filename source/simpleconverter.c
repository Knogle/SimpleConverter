#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/*
(1) CreateObject
(2) CreateDynamicObject
(3) MTA_SA


*/
int inputtype=0;
int outputtype=0;

objecttype()
{
	printf("\nValid Object types\n");
	printf("CreateObject: (1)\n");
	printf("CreateDynamicObject: (2)\n");
	printf("MTA_SA: (3)\n");
	
}


int main ( int argc, char *argv[] )
{
	printf("\nSimple SA-MP/MTA-SA Object Converter\n");
	printf("\nCopyright (C) 2017  Fabian Druschke (Knogle)");
	printf("\nThis program comes with ABSOLUTELY NO WARRANTY; \nfor details see http://www.gnu.org/licenses/.");
	printf("\nThis is free software, and you are welcome to redistribute it \n \n \n");

	if ( argc != 2 ) 
	{
		
		printf( "Usage: %s [filename]\n", argv[0] );
	}
	else 
	{	
		FILE *fIn = fopen(argv[1], "r");
		if ( fIn == 0 )
		{
			printf( "Could not open file\n" );
		}
		else
		{	
			
			int inputtype=0;
			int i=0;
			int model = 0, items = 0;
			float pos[3] = {0}, rot[3] = {0};
			
			objecttype();
			printf("\nSpecify input object type:\n");
			scanf("%i",&inputtype);
			if(inputtype != 1 || inputtype != 2 || inputtype != 3)
			{
				objecttype();
			}
			int outputtype=0;
			printf("\nSpecify output object type:\n");
			scanf("%i",&outputtype);
			if(outputtype != 1 || inputtype != 2 || inputtype != 3)
			{
				objecttype();
			}
			if(outputtype == inputtype)
			{
				printf("You cannot convert objects into the same type!");
			}
			else
			{
				
				
				FILE *fOut = fopen("output.txt", "wb");
				
				clock_t t;
				t = clock();
				if(inputtype == 1)//CreateObject
				{
					while ((items = fscanf(fIn, "%*[^-0123456789]%d%*[,]%f%*[,]%f%*[,]%f%*[,]%f%*[,]%f%*[,]%f%*s", &model, &pos[0], &pos[1], &pos[2], &rot[0], &rot[1], &rot[2])) != EOF)
					{	
						if(outputtype == 3)
						{
							if (items == 7)
							{
								fprintf(fOut, "<object id=\"object (Konvert)(%d)\" breakable=\"true\" interior=\"0\" collisions=\"true\" alpha=\"255\" model=\"%d\" doublesided=\"false\" scale=\"1\" dimension=\"0\" posX=\"%.7g\" posY=\"%.7g\" posZ=\"%.7g\" rotX=\"%.7g\" rotY=\"%.7g\" rotZ=\"%.7g\"></object>\n", i,model, pos[0], pos[1], pos[2], rot[0], rot[1], rot[2]);
								i++;
							}
						}
						if(outputtype == 2)
						{
							if (items == 7)
							{
								fprintf(fOut, "CreateDynamicObject(%d,%f,%f,%f,%f,%f,%f);// Object (%d)\n",model, pos[0], pos[1], pos[2], rot[0], rot[1], rot[2],i);
								i++;
							}
						}

						
					}
					
					
				}
				if(inputtype == 2)//CreateDynamicObject
				{
					while ((items = fscanf(fIn, "%*[^-0123456789]%d%*[,]%f%*[,]%f%*[,]%f%*[,]%f%*[,]%f%*[,]%f%*s", &model, &pos[0], &pos[1], &pos[2], &rot[0], &rot[1], &rot[2])) != EOF)
					{	
						if(outputtype == 3)
						{
							if (items == 7)
							{
								fprintf(fOut, "<object id=\"object (Konvert)(%d)\" breakable=\"true\" interior=\"0\" collisions=\"true\" alpha=\"255\" model=\"%d\" doublesided=\"false\" scale=\"1\" dimension=\"0\" posX=\"%.7g\" posY=\"%.7g\" posZ=\"%.7g\" rotX=\"%.7g\" rotY=\"%.7g\" rotZ=\"%.7g\"></object>\n", i,model, pos[0], pos[1], pos[2], rot[0], rot[1], rot[2]);
								i++;
							}
						}
						if(outputtype == 1)
						{
							if (items == 7)
							{
								fprintf(fOut, "CreateObject(%d,%f,%f,%f,%f,%f,%f);// Object (%d)\n",model, pos[0], pos[1], pos[2], rot[0], rot[1], rot[2],i);
								i++;
							}
						}

						
					}
					
					
				}
				if(inputtype == 3)//MTA_SA
				{
					char str1[32], str2[32], str3[32], str4[32], str5[32], str6[32] ,str7[32], str8[32], str9[32];
					char objstr[32];
					char line[512];
					 
					while (fgets(line, 512 , fIn) != NULL)
					{	
						if(strstr(line,"vehicle") || strstr(line,"ped")  || strstr(line,"removeWorld")) 
						continue;
						char searchchar = '\"';
						char replacechar = ' ';
						char *valueptr; 

						valueptr = strchr(line, searchchar);
						if(valueptr != NULL)
						*valueptr = replacechar;
						

						while (valueptr !=NULL) 
						{
							valueptr = strchr(valueptr + 1, searchchar);
							if(valueptr != NULL) 
							*valueptr = replacechar;
						}
						searchchar = '=';
						replacechar = ' ';
						
						valueptr = strchr(line, searchchar);
						if(valueptr != NULL)
						*valueptr = replacechar;
						

						while (valueptr !=NULL) 
						{
							valueptr = strchr(valueptr + 1, searchchar);
							if(valueptr != NULL) 
							*valueptr = replacechar;
						}
						
						if(strstr(line,"collision") && !(str1[0] == '\0')) 
						if(items = sscanf(line,"%*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %s %*s %s %*s %s %*s %s %*s %s %*s %s %*s %s",str1,str2,str3,str4,str5,str6  ,str7,str8,str9));
					
						
						if(str1[0] == '\0')
						if(items = sscanf(line,"%*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %s %*s %s %*s %s %*s %s %*s %s %*s %s %*s %s",str1,str2,str3,str4,str5,str6  ,str7,str8,str9));

						if(!strstr(line,"collision") && !(str1[0] == '\0')) 
						if(items = sscanf(line,"%*s %*s %*s %s %*s %*s %*s %*s %*s %*s %*s %*s %s %*s %*s %*s %*s %*s %s %*s %s %*s %s %*s %s %*s %s %*s %s %*s %s",str1,str2,str3,str4,str5,str6  ,str7,str8,str9));
						long int xmlmodelid = atoi(str2);
						float xmlPosX= atof(str4);
						float xmlPosY= atof(str5);
						float xmlPosZ= atof(str6);	
						float xmlRotX= atof(str7);
						float xmlRotY= atof(str8);
						float xmlRotZ= atof(str9);	
						{
							
							if(outputtype == 2)
							{
								if (items == 9)
								{
									fprintf(fOut, "CreateDynamicObjectObject(%li,%f,%f,%f,%f,%f,%f);// %s\n",xmlmodelid,xmlPosX, xmlPosY,xmlPosZ,xmlRotX,xmlRotY,xmlRotZ,str1);
									i++;
								}
							}
							if(outputtype == 1)
							{
								if (items == 9)
								{
									fprintf(fOut, "CreateObject(%li,%f,%f,%f,%f,%f,%f);// %s\n",xmlmodelid,xmlPosX, xmlPosY,xmlPosZ,xmlRotX,xmlRotY,xmlRotZ,str1);
									i++;
								}
							}
						}

						
					}
					
					
				}
				t = clock() - t;
				double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
				printf("The conversion took %f seconds to finish \n", time_taken);
				fclose(fOut);
				fclose(fIn);
				printf("%d Objekt(e) konvertiert.\n\n",i);
				return 0;
			}
		}
	}
}