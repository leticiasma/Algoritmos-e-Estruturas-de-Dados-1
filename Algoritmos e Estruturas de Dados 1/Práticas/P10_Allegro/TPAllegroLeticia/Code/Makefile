ALLEGRO_VERSION=5.0.10
MINGW_VERSION=4.7.0
FOLDER=C:\Users\User\Desktop\UFMG\AEDS\Allegro

FOLDER_NAME=\allegro-$(ALLEGRO_VERSION)-mingw-$(MINGW_VERSION)
PATH_ALLEGRO=$(FOLDER)$(FOLDER_NAME)
LIB_ALLEGRO=\lib\liballegro-$(ALLEGRO_VERSION)-monolith-mt.a
INCLUDE_ALLEGRO=\include

all: enduro.exe 	
	
enduro.exe: enduro.o
	gcc -o enduro.exe enduro.o $(PATH_ALLEGRO)$(LIB_ALLEGRO)

enduro.o: enduro.c
	gcc -I $(PATH_ALLEGRO)$(INCLUDE_ALLEGRO) -c enduro.c	
	
 
clean:
	del enduro.o 
	del enduro.exe
