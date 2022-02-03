#include <iostream>
#include <sstream>
    
    void scanstressvector (int n, int v[]){
            std::cout << "insira o numero de stress das " << n << " pessoas:"<<std::endl;
            
            for(int i=0; i<n; i++){
                std::cin >> v[i];
            }
    }

  
    int mostrartarefas (){
        int n=0;
        std::cout << "TAREFAS:\n";
        std::cout << "1. Alguem com o valor X esta na fila? \n";
        std::cout << "2. Quantas vezes o valor X apareceu na fila?\n";
        std::cout << "3. Em que posicao da fila aparece X pela primeira vez? \n";
        std::cout << "4. Dada a posicao para iniciar a busca, qual a proxima posicao em que aparece X? \n";
        std::cout << "5. qual o menor valor da lista? \n";
        std::cout << "6. qual a posicao do menor valor da lista? \n";
        std::cout << "7. Dada a posicao para iniciar a busca, qual a posicao do menor valor da lista? \n";
        std::cout << "8. qual a posicao do HOMEM mais calmo? (menor valor maior que 0) \n";
        std::cout << "9. qual a media de stress da fila? (abs) \n";
        std::cout << "10. Na fila existem mais homens ou mulheres?\n";
        std::cout << "11. O nivel de stress somado de todas as pessoas da primeira metade e maior que o nivel de stress somado das pessoas da segunda metade da fila? (abs) \n";
        std::cout << "12.  a media do stress dos homens e maior que a das mulheres? \n\n";
        std::cout << "escolha a tarefa pelo numero:";
        std::cin >> n;
        return n;
    }

    
    void um_valor_x_esta_na_fila (int n, int v[]){
        int x=0,cont=0;
        std::cout << "Digite o valor que quer encontrar na fila\n";
        std::cin >>x;
        
        for(int i=0; i<n;i++){
            if(v[i]==x) cont++;
        }

        if(cont>0){std::cout << x <<" esta na fila"<<std::endl;
        }else{ std::cout << x <<" nao esta na fila"<<std::endl;}
    }

    void dois_qnts_x_na_fila (int n, int v[]){
        int x=0,cont=0;
        std::cout << "Digite o valor que deseja saber quantas vezes aparece na fila\n";
        std::cin >>x;
        
        for(int i=0; i<n;i++){
            if(v[i]==x) cont++;
        }

        std::cout << x <<" aparece "<< cont <<" vezes na fila" <<std::endl;
    }

    void tres_primeiro_x_na_fila (int n, int v[]){
        int x=0;
        std::cout << "Digite o valor que deseja saber sua primeira aparicao\n";
        std::cin >>x;
        
        for(int i=0; i<n ;i++){
            if(v[i]==x){
                std::cout << x <<" aparece pela primeira vez na posicao "<< (i+1) <<std::endl;
                break;
            }
        }
    }

    void quatro_posicaodex_dado_inicio(int n, int v[]){
        int posi=0,x=0;
        std::cout << "Digite a posicao que deseja iniciar a busca\n";
        std::cin >>posi;
        std::cout << "Digite o valor que deseja saber sua primeira aparicao\n";
        std::cin >>x;
        for(int i=(posi-1); i<n ;i++){
            if(v[i]==x){
                std::cout << x <<" aparece pela primeira vez na posicao "<< (i+1)-(posi-1) <<std::endl;
                break;
            }
        }
        
    }

    void cinco_menorvalor(int n, int v[]){
        int menor=0;
        std::cout << "O menor valor do vetor e:\n";
 
        menor=v[0];
        for(int i=0; i<n ;i++){
            if(v[i]<menor) menor=v[i];
        }

        std::cout << menor <<std::endl;
    }

    void seis_posicao_menorvalor(int n, int v[]){
        int menor=0,aux=0;
        menor=v[0];
        for(int i=0; i<n ;i++){
            if(v[i]<menor){menor=v[i];
            aux=(i+1);}
        }

        std::cout << "o menor valor " << menor << " esta na posicao: "<< aux <<std::endl;
    }

    void sete__posicao_menorvalor_dadoinicio(int n, int v[]){
        int posicao=0,menor=0,aux=0;
        std::cout << "Digite a posicao que deseja iniciar a busca:\n";
        std::cin >>posicao;
        menor=v[posicao-1];
        for(int i=(posicao-1); i<n ;i++){
            if(v[i]<menor){menor=v[i];
            aux=((i+1)-(posicao-1));}
        }

        std::cout << "o menor valor: "<< menor << "esta na posicao: " << aux <<std::endl;
    }

    void oito_homemcalmo(int n, int v[]){
        int menor=100;
        for (int i=0; i<n; i++){
            if(v[i]<menor && v[i]>0) menor=v[i];
        }
        std::cout << menor <<" e o homem mais calmo"<<std::endl;
    } 

    void nove_media_stress(int n, int v[]){
        int mulheres=0,homens=0;
        std::cout << "a media de stress da fila e:\n";
        for(int i=0; i<n; i++){
            if(v[i]<0) mulheres=mulheres+(v[i]*-1);
            if(v[i]>0) homens=homens+v[i];
        } 
        std::cout << (float)(mulheres+homens)/n <<std::endl; 
    }

    void dez_maishomens_oumulheres(int n, int v[]){
        int mulheres=0,homens=0;
        for(int i=0; i<n; i++){
            if(v[i]<0) mulheres++;
            if(v[i]>0) homens++;
        } 
        if(mulheres>homens){std::cout << "Ha mais mulheres";
        }else{ if(mulheres<homens){ std::cout << "ha mais homens";
        }else{ std::cout << "ha a mesma quantidade de homens e mulheres";}}
    }

    void onze_metade(int n, int v[]){
        if(n%2==0){
            int soma1=0,soma2=0;
            for(int i=0; i<(n/2); i++){
                soma1=soma1+abs(v[i]);
            }
            for(int i=(n/2); i<n; i++){
                soma2=soma2+abs(v[i]);
            }
            std::cout << "stress primeira metade: " << soma1 <<std::endl;
            std::cout << "stress segunda metade: " << soma2 <<std::endl;
        }else{
            int soma3=0,soma4=0;
            for(int i=0; i<((n+1)/2); i++){
                soma3=soma3+abs(v[i]);
            }
            for(int i=((n-1)/2); i<n; i++){
                soma4=soma4+abs(v[i]);
            }
            std::cout << "stress primeira metade: "<< soma3 <<std::endl;
            std::cout << "stress segunda metade: " <<soma4 <<std::endl;
        }
    }

    void doze_stress(int n, int v[]){
      float mulheres=0,homens=0,qtdm=0,qtdh=0;
        for(int i=0; i<n; i++){
            if(v[i]<0){mulheres=mulheres+(v[i]*-1);
            qtdm++;}
            if(v[i]>0) {homens=homens+v[i];
            qtdh++;}
        }
        std::cout << "Stress dos homens: " << homens/qtdh <<std::endl;
        std::cout << "Stress das mulheres: " << mulheres/qtdm <<std::endl;

    }

    

    void executartarefas(int tarefa, int n, int v[]){
    
       switch (tarefa){
         case 1:
            um_valor_x_esta_na_fila(n,v);
            break;
         case 2:
            dois_qnts_x_na_fila(n,v);
            break;
        case 3:
            tres_primeiro_x_na_fila(n,v);
            break;
        case 4:
            quatro_posicaodex_dado_inicio(n,v);
            break;
        case 5:
            cinco_menorvalor(n,v);
            break;
        case 6:
            seis_posicao_menorvalor(n,v);
            break;
        case 7:
            sete__posicao_menorvalor_dadoinicio(n,v);
            break;
        case 8:
            oito_homemcalmo(n,v);
            break;
        case 9:
            nove_media_stress(n,v);
            break;
        case 10:
            dez_maishomens_oumulheres(n,v);
            break;
        case 11:
            onze_metade(n,v);
            break;
        case 12:
            doze_stress(n,v);
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