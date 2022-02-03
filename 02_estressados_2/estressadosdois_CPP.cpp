#include <iostream>

    
    void scanstressvector (int n, int v[]){
            std::cout << "insira o numero de stress das " << n << " pessoas:"<<std::endl;
            
            for(int i=0; i<n; i++){
                std::cin >> v[i];
            }
    }

  
    int mostrartarefas (){
        int n=0;
        std::cout << "TAREFAS:\n";
        std::cout << "1. retornar um novo vetor copiando os valores do vetor de entrada \n";
        std::cout << "2. retorne uma lista com os homens (valores positivos)\n";
        std::cout << "3. retorne uma lista com as pessoas com stress menor que 10 (abs) \n";
        std::cout << "4. retorne uma lista com as mulheres com nível de stress menor que 10.(negativos menor que 10) \n";
        std::cout << "5. inverter_com_copia \n";
        std::cout << "6. reverter_inplace \n";
        std::cout << "7. sortear \n";
        std::cout << "8. embaralhar \n";
        std::cout << "9. ordenar - selection sort utilizando \n";
        std::cout << "10. O fiscal permitiu a entrada de um único representante de cada valor, ou seja, uma lista dos valores que aparecem na fila sem repetição. Que conjunto foi formado?\n";
        std::cout << "11. Qual a lista dos diferentes níveis de stress que aparecem? \n";
        std::cout << "12.  quais pessoas ficaram na fila após remover um exemplar de cada valor?\n\n";
        std::cout << "escolha a tarefa pelo numero:";
        std::cin >> n;
        return n;
    }

    
    void um_clonarvetor (int n, int v[]){
        int b[n];
        std::cout << "Novo vetor: \n";
 
        
        for(int i=0; i<n;i++){
            b[i]=v[i];
        }
        std::cout<< "[ ";
        for(int i=0; i<n;i++){
            std::cout<< b[i]<< " ";
        }
        std::cout<< "]";
    }

    void dois_retonarhomens_positivos (int n, int v[]){
        int cont=0;
        for(int i=0; i<n;i++){
            if(v[i]>0){ 
                std::cout<< v[i] << " ";
                cont+=1;
            }
        } 
        if(cont==0){std::cout << "nao ha homens\n";}   
    }

    void tres_stressmenorqdez (int n, int v[]){
        int cont=0;
        for(int i=0; i<n;i++){
            if(abs(v[i])>0 && abs(v[i])<10){ 
                std::cout<< v[i] << " ";
                cont+=1;
            }
        } 
        if(cont==0){std::cout << "nao ha pessoas tranquilas\n";}  
    }

    void quatro_mulheresstress_menorqdez(int n, int v[]){
        int cont=0;
        for(int i=0; i<n;i++){
            if(v[i]<0 && abs(v[i])>0 && abs(v[i])<10){ 
                std::cout<< v[i] << " ";
                cont+=1;
            }
        } 
        if(cont==0){std::cout << "nao ha mulheres tranquilas\n";}  
        
    }

    void cinco_inverter_com_copia(int n, int v[]){
        int b[n];
        for(int i=0; i<n;i++){
            b[(n-1)-i]=v[i];
            }
        
        for(int i=0; i<n;i++){
            std::cout << b[i] << " ";
            }
    }

    void seis_reverter_inplace(int n, int v[]){
        int b[n],aux=0,aux2=0;
        if(n%2==0){
        for(int i=0; i<n/2;i++){
            aux=v[i];
            aux2=v[(n-1)-i];
            v[(n-1)-i]=aux;
            v[i]=aux2;
            }
        }else{
            for(int i=0; i<(n+1)/2;i++){
            aux=v[i];
            aux2=v[(n-1)-i];
            v[(n-1)-i]=aux;
            v[i]=aux2;
            }  
        }
        
        for(int i=0; i<n;i++){
            std::cout << v[i] << " ";
            }
    }

    void sete_sortear(int n, int v[]){     
        std::cout << v[(rand() %(n-1))];
    }

    void oito_embaralhar(int n, int v[]){
        int randon=0,aux=0;
        for (int i=0; i<n; i++){
            randon=(rand() %(n-1));
            aux=v[i];
            v[i]=v[randon];
            v[randon]=aux;
        }

        for(int i=0;i<n;i++){
            std::cout << v[i] << " ";
        }
    } 

    void nove_ordenar(int n, int v[]){
        int aux=0;
        for(int i=0; i<n; i++){
           for(int x=i;x<n;x++){
               if(v[i]>v[x]){
                   aux=v[i];
                   v[i]=v[x];
                   v[x]=aux;
               }
           } 
        }

        for(int i=0;i<n;i++){
            std::cout << v[i] << " ";
        }
               
        
    }

    void dez_eliminar_repetidos(int n, int v[]){
        for (int i=0;i<n;i++){
            int cont=0;
            for(int j=(i+1);j<n;j++){
                if(v[i]==v[j]){
                    cont++;
                }
            }
            if(cont==0) std::cout <<v[i] <<" ";
        }
    }

    void onze_stresslvl(int n, int v[]){
        for (int i=0;i<n;i++){
              if(v[i]<0){v[i]=v[i]*(-1);}
            }

        for (int i=0;i<n;i++){
            int cont=0;
            for(int j=(i+1);j<n;j++){
                if(v[i]==v[j]){
                    cont++;
                }
            }
            if(cont==0) std::cout <<v[i] <<" ";
        }
    }

    /*void doze_eliminar_um_de_cada(int n, int v[]){
        
                        ;-;

    }*/

    

    void executartarefas(int tarefa, int n, int v[]){
    
       switch (tarefa){
         case 1:
            um_clonarvetor(n,v);
            break;
         case 2:
            dois_retonarhomens_positivos(n,v);
            break;
        case 3:
            tres_stressmenorqdez(n,v);
            break;
        case 4:
            quatro_mulheresstress_menorqdez(n,v);
            break;
        case 5:
            cinco_inverter_com_copia(n,v);
            break;
        case 6:
            seis_reverter_inplace(n,v);
            break;
        case 7:
            sete_sortear(n,v);
            break;
        case 8:
            oito_embaralhar(n,v);
            break;
        case 9:
            nove_ordenar(n,v);
            break;
        case 10:
            dez_eliminar_repetidos(n,v);
            break;
        case 11:
            onze_stresslvl(n,v);
            break;
        case 12:
            std::cout <<";-;"<<std::endl;
            break;
         default:
            std::cout << "numero invalido\n";
            break;
        } 
    }

int main (){
    int NdePessoas=0,tarefa=0;
    std::cout << "insira o numero de pessoas da fila:" << std::endl; 
    std::cin >> NdePessoas;
    int v[NdePessoas];
    scanstressvector(NdePessoas,v);
    tarefa=mostrartarefas();
    executartarefas(tarefa,NdePessoas,v);
    return 0;
}