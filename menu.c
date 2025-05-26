#include "menu.h"

void menuNBT(){
	Isi_Tree pohon;
    int jumlahNode;
    int pilihan;
	do{
		printf("\x1b[H\x1b[J");
		printf(" ===== Non Binary Tree =====\n");
	    printf("1. Membuat Tree Baru\n");
	    printf("2. Traversal Pre Order\n");
	    printf("3. Traversal In Order\n");
	    printf("4. Traversal Post Order\n");
	    printf("5. Traversal Level Order\n");
	    printf("6. Print Tree\n");
	    printf("7. Jumlah Daun Tree\n");
	    printf("8. Search Node Tree\n");
	    printf("9. Mencari level node Tree\n");
	    printf("10. Kedalaman tree\n");
	    printf("11. Membandingkan 2 node Tree\n");
    	printf("12. Exit\n");
    	printf("Pilih Menu: ");
        scanf("%d", &pilihan);
        getchar();
		switch (pilihan) {
            case 1:{
            	printf("\x1b[H\x1b[J");
                printf("Masukkan jumlah node pada tree: ");
			    scanf("%d", &jumlahNode);
			
			    Create_tree(&pohon, jumlahNode);
				break;
			}

            case 2:{
            	printf("\x1b[H\x1b[J");
                printf("\n--- Traversal ---\n");
			    printf("Preorder     : ");
			    PreOrder(pohon, 1);
			    
			    printf("\nTekan Enter untuk kembali ke menu...");
				getchar();
				break;
			}
                
            case 3:{
            	printf("\x1b[H\x1b[J");
            	printf("\n--- Traversal ---\n");
                printf("\nInorder      : ");
    			InOrder(pohon, 1);
    			
    			printf("\nTekan Enter untuk kembali ke menu...");
				getchar();
				break;
			}

            case 4: {
            	printf("\x1b[H\x1b[J");
            	printf("\n--- Traversal ---\n");
				printf("\nPostorder    : ");
    			PostOrder(pohon, 1);
    			
    			printf("\nTekan Enter untuk kembali ke menu...");
				getchar();
                break;
            }

            case 5: {
            	printf("\x1b[H\x1b[J");
            	printf("\n--- Traversal ---\n");
            	printf("\nLevel Order  : ");
    			Level_order(pohon);
    			
    			printf("\nTekan Enter untuk kembali ke menu...");
				getchar();
                break;
            }

            case 6: {
            	printf("\x1b[H\x1b[J");
            	printf("\n--- Tree ---\n");
            	
    			PrintTree(pohon);
    			
    			printf("\nJumlah elemen      : %d\n", nbElmt(pohon));
    			
    			printf("\nTekan Enter untuk kembali ke menu...");
				getchar();
                break;
            }

            case 7: {
            	printf("\x1b[H\x1b[J");
            	printf("\n--- Informasi Tree ---\n");
            	printf("Jumlah daun        : %d\n", nbDaun(pohon));
            	
            	printf("\nTekan Enter untuk kembali ke menu...");
				getchar();
                break;
            }

            case 8: {
            	printf("\x1b[H\x1b[J");
            	char cari;
			    printf("Masukkan Node yang ingin dicari: ");
			    scanf(" %c", &cari);
			
			    if (Search(pohon, cari)) {
			        printf("Node '%c' ditemukan dalam tree.\n", cari);
			    } else {
			        printf("Node '%c' tidak ditemukan dalam tree.\n", cari);
			    }
			    
			    printf("\nTekan Enter untuk kembali ke menu...");
			    while (getchar() != '\n'); 
			    getchar();
				break;
			}
                
            case 9:{
            	printf("\x1b[H\x1b[J");
            	char cari;
			    printf("\nMasukkan karakter yang ingin dicari level-nya: ");
			    scanf(" %c", &cari);
			    int lvl = Level(pohon, cari);
			    if (lvl != -1)
			        printf("Level dari %c adalah %d\n", cari, lvl);
			    else
			        printf("Node %c tidak ditemukan\n", cari);
			        
			    printf("\nTekan Enter untuk kembali ke menu...");
			    while (getchar() != '\n'); 
			    getchar();
				break;
			}
            
            case 10:{
            	printf("\x1b[H\x1b[J");
            	printf("\n--- Informasi Tree ---\n");
            	printf("Kedalaman (depth)  : %d\n", Depth(pohon, 1));
            	
            	printf("\nTekan Enter untuk kembali ke menu...");
				getchar();
				break;
			}
			
			case 11: {
			    printf("\x1b[H\x1b[J");
			    infotype a, b;
			
			    printf("Masukkan data pertama di tree: ");
			    scanf(" %c", &a);
			
			    printf("Masukkan data kedua di tree: ");
			    scanf(" %c", &b);
			
			    infotype hasil = Max(pohon, a, b);
			    if (hasil != -1) {
			        printf("Nilai maksimum dari '%c' dan '%c' adalah: '%c'\n", a, b, hasil);
			    } else {
			        printf("Salah satu atau kedua data tidak ditemukan dalam tree.\n");
			    }
			
			    printf("\nTekan Enter untuk kembali ke menu...");
			    while (getchar() != '\n'); // membersihkan buffer
			    getchar(); // tunggu enter
			    break;
			}


            	
            case 12:{
            	printf("\x1b[H\x1b[J");
            	printf("Log Out.....\n");
				break;
			}
            	
            default:
                printf("Pilihan tidak valid.\n");
        }
	}while (pilihan != 12);
}
