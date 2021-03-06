#include <stdlib.h>
#include <getopt.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

extern FILE* yyin;
extern int yyparse();

//FLAGS
static int verbose_flag;
int directinput = 0;

//functions
//arguments qui ne sont pas prévus, donc des fichiers si la bonne extension, erreur sinon
void parse_argv_ext(const char* ext_ez, vector<char*> &fic_ezl, char * fic_cmp){
	for(unsigned int j = 0; j < strlen(ext_ez) ; ++j){
    	//si l'extension est mauvaise
        if(ext_ez[j] != fic_cmp[strlen(fic_cmp)-strlen(ext_ez)+j]){
        	return ;
        }
        //si l'extension est bonne
        if(j == strlen(ext_ez)-1){
			//on garde le fichier sous le coude
			fic_ezl.push_back(fic_cmp);
        }
	}
}

//main
int main ( int argc , char ** argv ){
	int opt;

	//boucle pour les arguments en ligne de commande programmés
	while(1){
		//options
		static struct option long_options[] = {
			// flags
			{"verbose",		no_argument,	&verbose_flag, 	1},
			{"brief",		no_argument,	&verbose_flag, 	0},
			{"noexec",		no_argument,	0, 				0},
			{"directinput",	no_argument,	&directinput,	1},
			
			//autres
			{"help",			no_argument,		0, 	'h'},
			{"optimisation",	required_argument,	0, 	'O'},
			{"warning",			no_argument,		0, 	'w'},
			{"output",			required_argument,	0, 	'o'},
			{0, 0, 0, 0}
		};
		
		//getopt_long recupere l'option ici
		int option_index = 0;
		
		opt = getopt_long(argc, argv, "ho:f:O:w", long_options, &option_index);
		
		//fin des options
		if(opt == -1){
			break;
		}
		
		//options en cours
		switch(opt){
			//flags
			case 0:
				if (long_options[option_index].flag != 0)
					break;
				if (string(long_options[option_index].name) == "noexec")
					cout << "Ne pas lancer l'exécutable" << endl;
				break;
			//options
			case 'h':
				cout << "Faire une aide" << endl;
				break;

			case 'o':
				cout << "Gerer un output" << endl;
				break;
			case 'w':
				cout << "Afficher les warning" << endl;
				break;
			case 'O':
				cout << "Option d'optimisation niveau: " << optarg << endl;
				break;
			//option inconnue, s'il y a une option avec un tiret ou deux, c'est forcement autre chose qu'un fichier donc erreur
			case '?':
				cout << "Option inconnue : " << option_index << endl;
				exit(EXIT_FAILURE);
			//defaut
			default:
				abort ();
		}
	}
	
	//vecteurs des fichiers a traiter
    vector<char*> fic_ezl;
//	fic_ezl.push_back("/home/etudiant/Cl…/ezlanguage/tests/exemple.ez");
    //tableaux des extensions des fichiers a traiter
    int nb_ext = 2;
    const string ext_ez[nb_ext] = {".ez", ".ezl"};
    //ajout des fichiers a parser
	for(int i=0; i<nb_ext; ++i){
		for(int j=optind; j<argc; ++j){
			parse_argv_ext(ext_ez[i].c_str(), fic_ezl, argv[j]);
		}
	}        
    
    //test des arguments restant
	cout << "Il y a "<< argc<< " arguments"<<endl;
	for(int i=optind+1; i<argc; ++i){
		cout<< "Parsing du "<< i<< "eme fichier : "<< argv[i]<< endl;
		if(!(find(fic_ezl.begin(), fic_ezl.end(), argv[i]) != fic_ezl.end())){
			cerr << "Fichier invalide ou option inconnue : " << argv[i] << endl;
			exit(EXIT_FAILURE);
		}
	}


	// Boucle qui execute tout les fichiers
	if(!directinput){
		for(unsigned int i=0; i<fic_ezl.size(); ++i){
			cout << "\033[1;36mParsing du fichier : \033[1;37m" << fic_ezl[i] << endl;
			cout << "\033[1;36m=====================================\033[0m" << endl;
			yyin = fopen(fic_ezl[i], "r");
			if(!yyin){
				cerr << "Erreur lors de l'ouverture du fichier : " << fic_ezl[i] << endl;
			}else{
				yyparse();
			}
			cout << "\033[1;36m=====================================\033[0m" << endl;
			cout << endl;
		}
	}else{
		cout << "\033[1;36mDébut de votre parsing : \033[1;37m" << endl;
		cout << "\033[1;36m=====================================\033[0m" << endl;
		yyparse();
		cout << "\033[1;36m=====================================\033[0m" << endl;
	}
	cout << "\033[1;36mFin du parsing\033[0m" << endl;

    exit(EXIT_SUCCESS);
}

