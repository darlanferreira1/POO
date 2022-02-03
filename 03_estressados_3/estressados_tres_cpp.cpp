#include <iostream>
#include <iterator>
#include <vector>

    
    void scanstressvector (int n, int v[]){
            std::cout << "insira o numero de stress das " << n << " pessoas:"<<std::endl;
            
            for(int i=0; i<n; i++){
                std::cin >> v[i];
            }
    }

  
    int mostrartarefas (){
        int n=0;
        std::cout << "TAREFAS:\n";
        std::cout << "1. Quais PESSOAS eram as únicas representantes do seu nível de stress na fila? (abs) \n";
        std::cout << "2. Qual a maior quantidade de ocorrências do mesmo nível de stress. (abs)\n";
        std::cout << "3. Quais os níveis de stress mais recorrentes. (abs) \n";
        std::cout << "4. Quando alguém super estressado(>50) está ao lado de duas pessoas muito estressadas(>30) pode dar briga. Quantas vezes essa situação acontece? \n";
        std::cout << "5. Se alguém hiper estressado(>80) estiver ao lado de pelo menos uma pessoa bem tranquila (<10) ela vai ser apaziguada. Em que posições estão esses que serão apaziguados?\n";
        std::cout << "6. Duas ou mais pessoas do mesmo sexo seguidas podem formar um time. Quantos times existem na fila? \n";
        std::cout << "7. Qual o maior time que apareceu na fila? \n";
        std::cout << "8. Quantas pessoas não estavam em um time? \n";
        std::cout << "9. Casais são formados quando quando um homem e uma mulher com o mesmo nível de stress são formados. O 3 e o -3 formam um casal. Os participantes fossem orientados a sair da fila e procurar seu par. Quantos casais poderiam ser formados? \n";
        std::cout << "10. Pedimos pros participantes se organizassem em trios. Todos os 3 deveriam estar com o mesmo nível de stress.Quantos trios podem ser formados?\n";
        std::cout << "11. Dado a pessoa X, como fica a fila após remover X? \n";
        std::cout << "12.  Como fica a fila se eu inserir a pessoa X na posição Y.\n";
        std::cout << "13.  O coordenador disse: se você está do lado de alguém da com o mesmo nível de stress que você, saia da fila com ele. Quando os pares saiam, as vezes se formavam novos pares que também saíam. Quem ficou na fila?\n\n";
        std::cout << "escolha a tarefa pelo numero:";
        std::cin >> n;
        return n;
    }

    
    void um_unicos_representantes (int n, int v[]){
         for (int i=0;i<n;i++){
            int cont=0;
            for(int j=0;j<n;j++){
                if((-1)*(v[i])==(v[j]) || v[i]==v[j]){
                    cont++;
                }
            }
            if(cont==1) std::cout <<v[i] <<" ";
        }
    }

    void dois_maiorocorrencia (int n, int v[]){
        int maiorcont=0;
        for (int i=0;i<n;i++){
            int cont=0;
            for(int j=0;j<n;j++){
                if((-1)*(v[i])==(v[j]) || v[i]==v[j]){
                    cont++;
                }
                if(cont>maiorcont) maiorcont=cont;
            }
        }
        std::cout << maiorcont <<std::endl;  
    }

    void tres_stressmaisrecorentes (int n, int v[]){
       int maiorcont=0,aux=0;
        for (int i=0;i<n;i++){
            int cont=0;
            for(int j=0;j<n;j++){
                if((-1)*(v[i])==(v[j]) || v[i]==v[j]){
                    cont++;
                }
                if(cont>maiorcont) {maiorcont=cont;
                aux=v[i];
                }
            } 
        }
        std::cout<<aux<<std::endl;
         
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
            std::vector<int> vet;
            for(int i=0;i<n;i++){
                vet.push_back(v[i]);
                }
    }

    void treze (int n, int v[]){

        
    }*/

    

    void executartarefas(int tarefa, int n, int v[]){
    
       switch (tarefa){
         case 1:
            um_unicos_representantes(n,v);
            break;
         case 2:
            dois_maiorocorrencia(n,v);
            break;
        case 3:
            tres_stressmaisrecorentes(n,v);
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
        case 13:
            //treze(n,v);
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