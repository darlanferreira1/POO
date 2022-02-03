#include <stdio.h>
    
    void scanstressvector (int n, int v[n]){
            printf("insira o numero de stress das %d pessoas:\n" ,n);
            
            for(int i=0; i<n; i++){
                scanf("%d",&v[i]);
            }
    }

  
    int mostrartarefas (){
        int n=0;
        printf("TAREFAS:\n");
        printf("1. Alguem com o valor X esta na fila? \n");
        printf("2. Quantas vezes o valor X apareceu na fila?\n");
        printf("3. Em que posicao da fila aparece X pela primeira vez? \n");
        printf("4. Dada a posicao para iniciar a busca, qual a proxima posicao em que aparece X? \n");
        printf("5. qual o menor valor da lista? \n");
        printf("6. qual a posicao do menor valor da lista? \n");
        printf("7. Dada a posicao para iniciar a busca, qual a posicao do menor valor da lista? \n");
        printf("8. qual a posicao do HOMEM mais calmo? (menor valor maior que 0) \n");
        printf("9. qual a media de stress da fila? (abs) \n");
        printf("10. Na fila existem mais homens ou mulheres?\n");
        printf("11. O nivel de stress somado de todas as pessoas da primeira metade e maior que o nivel de stress somado das pessoas da segunda metade da fila? (abs) \n");
        printf("12.  a media do stress dos homens e maior que a das mulheres? \n\n");
        printf("escolha a tarefa pelo numero:");
        scanf("%d",&n);
        return n;
    }

    
    void um_valor_x_esta_na_fila (int n, int v[n]){
        int x=0,cont=0;
        printf("Digite o valor que quer encontrar na fila\n");
        scanf("%d",&x);
        
        for(int i=0; i<n;i++){
            if(v[i]==x) cont++;
        }

        if(cont>0){printf("%d esta na fila",x);
        }else{ printf("%d nao esta na fila",x);}
    }

    void dois_qnts_x_na_fila (int n, int v[n]){
        int x=0,cont=0;
        printf("Digite o valor que deseja saber quantas vezes aparece na fila\n");
        scanf("%d",&x);
        
        for(int i=0; i<n;i++){
            if(v[i]==x) cont++;
        }

        printf("%d aparece %d vezes na fila",x,cont);
    }

    void tres_primeiro_x_na_fila (int n, int v[n]){
        int x=0;
        printf("Digite o valor que deseja saber sua primeira aparicao\n");
        scanf("%d",&x);
        
        for(int i=0; i<n ;i++){
            if(v[i]==x){
                printf("%d aparece pela primeira vez na posicao %d\n",x,(i+1));
                return 0;
            }
        }
    }

    void quatro_posicaodex_dado_inicio(int n, int v[n]){
        int posi=0,x=0;
        printf("Digite a posicao que deseja iniciar a busca\n");
        scanf("%d",&posi);
        printf("Digite o valor que deseja saber sua primeira aparicao\n");
        scanf("%d",&x);
        for(int i=(posi-1); i<n ;i++){
            if(v[i]==x){
                printf("%d aparece pela primeira vez na posicao %d/n",x,((i+1)-(posi-1)));
                return 0;
            }
        }
        
    }

    void cinco_menorvalor(int n, int v[n]){
        int menor=0;
        printf("O menor valor do vetor e:\n");
 
        menor=v[0];
        for(int i=0; i<n ;i++){
            if(v[i]<menor) menor=v[i];
        }

        printf("%d\n",menor);
    }

    void seis_posicao_menorvalor(int n, int v[n]){
        int menor=0,aux=0;
        menor=v[0];
        for(int i=0; i<n ;i++){
            if(v[i]<menor){menor=v[i];
            aux=(i+1);}
        }

        printf("o menor valor: %d, esta na posicao: %d\n",menor,aux);
    }

    void sete__posicao_menorvalor_dadoinicio(int n, int v[n]){
        int posicao=0,menor=0,aux=0;
        printf("Digite a posicao que deseja iniciar a busca:\n");
        scanf("%d",&posicao);
        menor=v[posicao-1];
        for(int i=(posicao-1); i<n ;i++){
            if(v[i]<menor){menor=v[i];
            aux=((i+1)-(posicao-1));}
        }

        printf("o menor valor: %d, esta na posicao: %d\n",menor,aux);
    }

    void oito_homemcalmo(int n, int v[n]){
        int menor=100;
        for (int i=0; i<n; i++){
            if(v[i]<menor && v[i]>0) menor=v[i];
        }
        printf("%d e o homem mais calmo",menor);
    } 

    void nove_media_stress(int n, int v[n]){
        int mulheres=0,homens=0;
        printf("a media de stress da fila e:\n");
        for(int i=0; i<n; i++){
            if(v[i]<0) mulheres=mulheres+(v[i]*-1);
            if(v[i]>0) homens=homens+v[i];
        } 
        printf("%d",(mulheres+homens)/n); 
    }

    void dez_maishomens_oumulheres(int n, int v[n]){
        int mulheres=0,homens=0;
        for(int i=0; i<n; i++){
            if(v[i]<0) mulheres++;
            if(v[i]>0) homens++;
        } 
        if(mulheres>homens){printf("Ha mais mulheres");
        }else{ if(mulheres<homens){ printf("ha mais homens");
        }else{ printf("ha a mesma quantidade de homens e mulheres");}}
    }

    void onze_metade(int n, int v[n]){
        if(n%2==0){
            int soma1=0,soma2=0;
            for(int i=0; i<(n/2); i++){
                soma1=soma1+abs(v[i]);
            }
            for(int i=(n/2); i<n; i++){
                soma2=soma2+abs(v[i]);
            }
            printf("stress primeira metade: %d\n",soma1);
            printf("stress segunda metade: %d\n",soma2);
        }else{
            int soma3=0,soma4=0;
            for(int i=0; i<((n+1)/2); i++){
                soma3=soma3+abs(v[i]);
            }
            for(int i=((n-1)/2); i<n; i++){
                soma4=soma4+abs(v[i]);
            }
            printf("stress primeira metade: %d\n",soma3);
            printf("stress segunda metade: %d\n",soma4);
        }
    }

    void doze_stress(int n, int v[n]){
      float mulheres=0,homens=0,qtdm=0,qtdh=0;
        for(int i=0; i<n; i++){
            if(v[i]<0){mulheres=mulheres+(v[i]*-1);
            qtdm++;}
            if(v[i]>0) {homens=homens+v[i];
            qtdh++;}
        }
        printf("Stress dos homens: %.2f\n",homens/qtdh);
        printf("Stress das mulheres: %.2f\n",mulheres/qtdm);

    }

    

    void executartarefas(int tarefa, int n, int v[n]){
    
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
            printf("numero invalido\n");
            break;
        } 
    }

int main (){
    int NdePessoas=0,tarefa=0;
    printf ("insira o numero de pessoas da fila:\n"); 
    scanf("%d",&NdePessoas);
    int v[NdePessoas];
    scanstressvector(NdePessoas,v);
    tarefa=mostrartarefas();
    executartarefas(tarefa,NdePessoas,v);
    system("pause");
    return 0;
}