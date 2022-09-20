#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//  HERE ARE THE STRUCTURES I AM USING
struct medication {
int code, quantite;
char nom[20];
float prix;
};
struct medication T_med[1000];

struct vende{
	char nom[20];
	int vendu;
	int jour, mois, annee;
	float prix;
};
struct vende T_vend[100];

// HERE ARE MY GLOBAL VARIABLES
int i;
int n;
float prix_ttc;

int c_med=0;
int c_vend=0;

// HERE ARE MY FUNCTIONS
void ajouter(){
	
	printf("TAPEZ combien de produit vous voullez ajouter:  ");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		printf("\n Le code de produit %d : ", i+1);
		scanf("%d",&T_med[c_med].code);
		
		printf("\n Le nom de produit %d : ", i+1);
		scanf("%s",&T_med[c_med].nom);
		
		printf("\n La quantite du produit %d : ", i+1);
		scanf("%d",&T_med[c_med].quantite);
		
		printf("\n Le prix du produit %d : ", i+1);
		scanf("%f",&T_med[c_med].prix);
		printf("\n");
		printf("\n-------------------------------\n");
		c_med++;
	}
	system("cls");
	
}


void afficher(){
	int j, a, b;
	float c;
	char s[100];
	do{
		printf("TYPE (1) pour afficher par ordre alphabetique ou TYPE (2) pour afficher par prix: ");
		scanf("%d",&n);	
	}while(n!=1 && n!=2);
	
	if(n==1){
		for(i=0;i<c_med;i++){
			for(j=i+1;j<c_med;j++){
				if(strcmp(T_med[i].nom,T_med[j].nom)>0){
					strcpy(s,T_med[i].nom);
					strcpy(T_med[i].nom,T_med[j].nom);
					strcpy(T_med[j].nom,s);
					
					a=T_med[i].code;
					T_med[i].code=T_med[j].code;
					T_med[j].code=a;
					
					b=T_med[i].quantite;
					T_med[i].quantite=T_med[j].quantite;
					T_med[j].quantite=b;
					
					c=T_med[i].prix;
					T_med[i].prix=T_med[j].prix;
					T_med[j].prix=c;
				}
			}
		}
		printf("\n  Voila l'ordre alphabetic des produits: ");
		for(i=0;i<c_med;i++){
			printf("\n Le code de produit     %d : %d", i+1, T_med[i].code);
			printf("\n Le nom de produit      %d : %s", i+1, T_med[i].nom);
			printf("\n La quantite du produit %d : %d", i+1, T_med[i].quantite);
			printf("\n Le prix du produit     %d : %.2f",i+1,T_med[i].prix);
			prix_ttc = T_med[i].prix + 0.15 * T_med[i].prix;
			printf("\n Le prix TTC du produit %d : %.2f",i+1, prix_ttc);
			printf("\n       -------------------------------\n");
		}
	}
	if(n==2){
		for(i=0;i<c_med;i++){
			for(j=i+1;j<c_med;j++){
				if(T_med[i].prix<T_med[j].prix){
					c=T_med[i].prix;
					T_med[i].prix=T_med[j].prix;
					T_med[j].prix=c;
					
					a=T_med[i].code;
					T_med[i].code=T_med[j].code;
					T_med[j].code=a;
					
					b=T_med[i].quantite;
					T_med[i].quantite=T_med[j].quantite;
					T_med[j].quantite=b;
					
					
					strcpy(s,T_med[i].nom);
					strcpy(T_med[i].nom,T_med[j].nom);
					strcpy(T_med[j].nom,s);
				}
			}
		}
		printf("\n  Voila l'ordre par prix: ");
		for(i=0;i<c_med;i++){
			printf("\n Le code de produit     %d : %d", i+1, T_med[i].code);
			printf("\n Le nom de produit      %d : %s", i+1, T_med[i].nom);
			printf("\n La quantite du produit %d : %d", i+1, T_med[i].quantite);
			printf("\n Le prix du produit     %d : %.2f",i+1,T_med[i].prix);
			prix_ttc = T_med[i].prix + 0.15 * T_med[i].prix;
			printf("\n Le prix TTC du produit %d : %.2f",i+1, prix_ttc);
			printf("\n       -------------------------------\n");
		}
	}
}

int ed_qte, ex_qte;
char nom_pro_vend[20];
int vende, h,m,s;
void mofidier(){
	printf("tapez le code de produit pour modifier la quantite: ");
	scanf("%d",&ed_qte);
	for(i=0;i<c_med;i++){
		if (ed_qte==T_med[i].code){
			ex_qte = T_med[i].quantite;
			printf("\ntapez la nouvelle quantite: ");
			scanf("%d",&T_med[i].quantite);
			if(T_med[i].quantite<ex_qte){
				vende = ex_qte - T_med[i].quantite;
				T_vend[c_vend].vendu= vende;
				///////////
				time_t t;
				time(&t); 
				struct tm *tmm = localtime(&t); 
				T_vend[i].jour= tmm->tm_mday;
				T_vend[i].mois= tmm->tm_mon + 1;
				T_vend[i].annee =tmm->tm_year + 1900;
				////////////
				T_vend[c_vend].prix= T_med[i].prix;
				strcpy(nom_pro_vend,T_med[i].nom);
				strcpy(T_vend[c_vend].nom,nom_pro_vend);
				
				c_vend++;	
			}
		}	
	}
	
}


void chercher(){
	int code, quantite;
	do{
		printf("TYPE (1) pour chrcher par code  ou TYPE (2) pour chrcher par quantite: ");
		scanf("%d",&n);	
	}while(n!=1 && n!=2);
	
	if(n==1){
		printf("Tapez le code: ");
		scanf("%d",&code);
		for(i=0;i<c_med;i++){
			if (code == T_med[i].code){
				printf("%s\n",T_med[i].nom);
   	            printf("prix de produit: %.2f \n", T_med[i].prix );
	            prix_ttc = T_med[i].prix + 0.15*T_med[i].prix;
	            printf("prix (TTC) de produit: %.2f \n", prix_ttc);
	            printf("\n---------------------------------------\n");
			}
		}
	}
	if(n==2){
		printf("Tapez la quantite: ");
		scanf("%d",&quantite);
		for(i=0;i<c_med;i++){
			if (quantite == T_med[i].quantite){
				printf("le nom de produit :   %s\n",T_med[i].nom);
   	            printf("prix de produit   : %.2f \n", T_med[i].prix );
	            prix_ttc = T_med[i].prix + 0.15*T_med[i].prix;
	            printf("price (TTC) of produit: %.2f \n", prix_ttc);
	            printf("\n---------------------------------------\n");
			}
		}
	}

}


void suprimer(){
	int code, index;
	printf("  Tapez le code de produit que vous voullez suprimer: ");
	printf("\n");
	scanf("%d",&code);
	for(i=0;i<c_med;i++){
		if(code==T_med[i].code){
			index = i;
			for(i = index; i<c_med;i++){
				T_med[i]=T_med[i+1];	
			}
			c_med--;		
		}
	}
	printf("   Les produits que vous avez actuellement: \n");
	for (i=0;i<c_med;i++){
		printf("\nLe nom de produit:  %s",T_med[i].nom);
		printf("\n");
	}

}


void revenue(){
	printf("\n   Les produit vendus aujourd'hui:  ");
	for(i=0;i<c_vend;i++){
		printf("\nle nom de produit:  %s", T_vend[i].nom);
		printf("\nla quantite de produit vendu:  %d", T_vend[i].vendu);
		printf("\nle prix d'un produit:  %.2f", T_vend[i].prix);
		prix_ttc = T_vend[i].prix + T_vend[i].prix * 0.15;
		printf("\nle prix TTC d'un produit:  %.2f", prix_ttc);
		
		
		printf("\nLa date: %d/%d/%d", T_vend[i].jour,T_vend[i].mois,T_vend[i].annee);
		printf("\n-------------------------------\n");
		printf("\n");
	}
}


void stats(){
	float total=0, moyenne=1;
	int s_vende=0;
	for(i=0;i<c_vend;i++){
		total+= T_vend[i].vendu * T_vend[i].prix;
		s_vende += T_vend[i].vendu;
	}
	printf("Le total de jour est   : %.2f\n", total);
	moyenne = total / s_vende;
	printf("La moyenne  de jour est: %.2f\n", moyenne);
	
	float min, max;
	max=T_vend[0].prix;
	for(i=1;i<c_vend;i++){
		if(T_vend[i].prix>max) max = T_vend[i].prix;
	} printf("Le max de ce jour est: %.2f\n", max );
	
	min=T_vend[0].prix;
	for(i=1;i<c_vend;i++){
		if(T_vend[i].prix<min) min = T_vend[i].prix;
	} printf("Le min de ce jour est: %.2f\n", min );

}


void stock(){
	printf("\n    VOILA les produits dont la quantité est inférieure à 3:  ");
	for(i=0;i<c_med;i++){
		if(T_med[i].quantite<3) {
			printf("\nle nom de produit:  %s", T_med[i].nom);
			printf("\nla quantite de produit:  %d", T_med[i].quantite);
			printf("\nle prix d'un produit:  %.2f", T_med[i].prix);
			prix_ttc = T_med[i].prix + T_med[i].prix * 0.15;
			printf("\nle prix TTC d'un produit:  %.2f", prix_ttc);
			printf("\n-------------------------------\n");
			printf("\n");
		}
	}

}

//

int main(){
	int choix;
	do{
	printf("\n   ------  BIENVENUE  ------   \n");
	printf("\n   1:    AJOUTER LES PRODUITS \n");
	printf("   2:    AFFICHER LES PRODUITS \n");
	printf("   3:    MODIFIER LA  QUANTITE \n");
	printf("   4:    CHERCHER UN PRODUIT \n");
	printf("   5:    SUPRIMER UN PRODUITS \n");
	printf("   6:    LE REVENUE \n");
	printf("   7:    STATISTICS \n");
	printf("   8:    STOCK \n");
	
	printf("\nchoisissez un nombre:  ");
	scanf("%d",&choix);

	switch (choix){
		case 1: system("cls");
			ajouter();
		break;
		case 2: system("cls");
			afficher();
		break;
		case 3: system("cls");
			mofidier();
		break;
			case 4: system("cls");
		chercher();
		break;
			case 5: system("cls");
		suprimer();
		break;
			case 6: system("cls");
		revenue();
		break;
			case 7: system("cls");
		stats();
		break;
			case 8: system("cls");
		stock();
		break;
		default: system("cls"); printf("\n   ERROR:   mauvais choix   \n");
	}
	}while(choix!=0);
}

