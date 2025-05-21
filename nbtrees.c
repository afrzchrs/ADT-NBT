#include "nbtrees.h"

/* Mengecek apakah Tree kosong */
boolean IsEmpty(Isi_Tree P) {
    return P[1].info == '\0'; 
}

/* Membuat Tree dengan Jml_Node */
void Create_tree(Isi_Tree *X, int Jml_Node) {
	// Inisialisasi semua elemen array ke nilai default
    for (int k = 1; k <= jml_maks; k++) {
        (*X)[k].info = '\0';
        (*X)[k].ps_fs = 0;
        (*X)[k].ps_nb = 0;
        (*X)[k].ps_pr = 0;
    }
    
    int index = 1, input, i = 0, j = 1; 
    if (Jml_Node != 0) {
        printf("Masukkan info untuk root : ");
        scanf(" %c", &(*X)[index].info);
        (*X)[index].ps_nb = 0;
        (*X)[index].ps_pr = 0;
        (*X)[index].ps_fs = 0;

        while (index != Jml_Node) {
            printf("Masukkan jumlah anak untuk %c : ", (*X)[j].info);
            scanf("%d", &input);
            for (i = 0; i < input; i++) {
                index++;
                printf("Masukkan anak ke %d : ", i + 1);
                scanf(" %c", &(*X)[index].info);
                (*X)[index].ps_pr = j;
                if (i == input - 1) {
                    (*X)[index].ps_nb = 0;
                } else {
                    (*X)[index].ps_nb = index + 1;
                }
                if (i == 0) {
                    (*X)[j].ps_fs = index;
                }
                (*X)[index].ps_fs = 0;
            }
            j++; 
        }
    }
}

void PreOrder(Isi_Tree P, int i) {
    if (i == 0) return;

    // root or parent
    printf("%c ", P[i].info); 

    // anak pertama (left)
    PreOrder(P, P[i].ps_fs); 

    // saudara berikutnya (right)
    PreOrder(P, P[i].ps_nb); 
}

void InOrder (Isi_Tree P, int i){
    if (i == 0) return;

    int child = P[i].ps_fs;
    if (child != 0) {
        // Traverse child pertama
        InOrder(P, child);
    }

    // Visit node sekarang (root)
    printf("%c ", P[i].info);

    // Traverse saudara dari child pertama
    if (child != 0) {
        child = P[child].ps_nb;
        while (child != 0) {
            InOrder(P, child);
            child = P[child].ps_nb;
        }
    }  
}

void PostOrder (Isi_Tree P, int i){
	if (i == 0) return;

    int child = P[i].ps_fs;
    while (child != 0) {
        PostOrder(P, child);
        child = P[child].ps_nb;
    }
 
    // Visit node sekarang (root)
    printf("%c ", P[i].info);
}

void Level_order(Isi_Tree X, int Maks_node) {
    int queue[21];  
    int front = 0, rear = 0;

    if (Maks_node == 0) return;

    queue[rear++] = 1; 

    while (front < rear) {
        int current = queue[front++];
        printf("%c ", X[current].info);

        int child = X[current].ps_fs;
        while (child != 0) {
            queue[rear++] = child;
            child = X[child].ps_nb; 
        }
    }
}

void PrintTree(Isi_Tree X) {
    int i = 1;
    while (X[i].info != '\0') {
        printf("\n --> index ke-%d \n", i);
        printf("---------------------------------------\n");
        printf("info array ke-%d : %c \n", i, X[i].info);
        if (X[i].ps_fs != 0) {
            printf("First son array ke-%d : %c \n", i, X[X[i].ps_fs].info);
        }else{
        	printf("First son array ke-%d : 0 \n", i);
		}
        if (X[i].ps_nb != 0) {
            printf("next brother array ke-%d : %c \n", i, X[X[i].ps_nb].info);
        }else{
        	printf("next brother array ke-%d : 0 \n", i);
		}
        if (X[i].ps_pr != 0) {
            printf("Parent array ke-%d : %c \n", i, X[X[i].ps_pr].info);
        }else{
        	printf("Parent array ke-%d : 0 \n", i);
		}
        printf("---------------------------------------\n");
        i++;
    }
}

boolean Search(Isi_Tree P, infotype X) {
    int i = 1;
    while (P[i].info != '\0') {
        if (P[i].info == X) return true;
        i++;
    }
    return false;
}

int nbElmt(Isi_Tree P) {
    int count = 0;
    int i = 1;
    while (P[i].info != '\0') {
        count++;
        i++;
    }
    return count;
}


int nbDaun(Isi_Tree P) {
    int count = 0;
    int i = 1;
    while (P[i].info != '\0') {
        if (P[i].ps_fs == 0) count++;
        i++;
    }
    return count;
}
 
int Level(Isi_Tree P, infotype X) {
    int i = 1;
    while (P[i].info != '\0') {
        if (P[i].info == X) {
            int level = 1;
            int parent = P[i].ps_pr;
            while (parent != 0) {
                level++;
                parent = P[parent].ps_pr;
            }
            return level - 1;
        }
        i++;
    }
    return -1;  
}

int Depth(Isi_Tree P, int i) {
    if (i == 0) return 0;

    int maxDepth = -1;
    int child = P[i].ps_fs;

    while (child != 0) {
        int d = Depth(P, child);
        if (d > maxDepth) maxDepth = d;
        child = P[child].ps_nb;
    }

    return maxDepth + 1;
}

int Max(Isi_Tree P, infotype Data1, infotype Data2) {
    int i = 1;
    int foundData1 = 0, foundData2 = 0;
    
    while (P[i].info != '\0') {
        if (P[i].info == Data1) {
            foundData1 = 1;  
        }
        if (P[i].info == Data2) {
            foundData2 = 1;  
        }
        i++;  
    }

    if (!foundData1 || !foundData2) {
        printf("Data tidak ditemukan dalam tree!\n");
        return -1;  
    }


    return (Data1 > Data2) ? Data1 : Data2;
}
 
