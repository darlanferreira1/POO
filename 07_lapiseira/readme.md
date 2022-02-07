# Lapiseira & Com vários grafites utilizando lista
![](figura.jpg)

<!--TOC_BEGIN-->
- [Lapiseira & Com vários grafites utilizando lista](#lapiseira--com-vários-grafites-utilizando-lista)
  - [Requisitos](#requisitos)
  - [Shell](#shell)
  - [Diagrama](#diagrama)
  - [Esqueleto](#esqueleto)
<!--TOC_END-->

Faça o modelo de uma lapiseira que pode conter vários.

## Requisitos
- Iniciar lapiseira
    - Inicia uma lapiseira de determinado calibre sem grafite.
    - Lapiseiras possuem um bico e um tambor.
    - O bico guarda o grafite que está em uso. 
    - O tambor guarda os grafites reservas.
- Inserir grafite
    - Insere um grafite passando
        - o calibre: float.
        - a dureza: string.
        - o tamanho em mm: int.
    - Não deve aceitar um grafite de calibre não compatível.
    - O grafite é colocado como o ÚLTIMO grafite do tambor.
- Puxar grafite
    - Puxa o grafite do tambor para o bico.
    - Se já tiver um grafite no bico, esse precisa ser removido primeiro.
- Remover grafite
    - Retira o grafite do bico.
- Escrever folha
    - Não é possível escrever se não há grafite no bico.
    - Quanto mais macio o grafite, mais rapidamente ele se acaba. Para simplificar, use a seguinte regra:
        - Grafite HB: 1mm por folha.
        - Grafite 2B: 2mm por folha.
        - Grafite 4B: 4mm por folha.
        - Grafite 6B: 6mm por folha.
        
    - O último centímetro de um grafite não pode ser aproveitado, quando o grafite estiver com 10mm, não é mais possível escrever e o grafite deve ser retirado.
    - Se não houver grafite suficiente para terminar a folha, avise que o texto ficou incompleto.
    - Avise quando o grafite acabar.


## Shell

```bash
#__case inserindo grafites
$init 0.5
$show
calibre: 0.5, bico: [], tambor: {}
$insert 0.7 2B 50
fail: calibre incompatível
$insert 0.5 2B 50
$show
calibre: 0.5, bico: [], tambor: {[0.5:2B:50]}
$insert 0.5 2B 30
$show
calibre: 0.5, bico: [], tambor: {[0.5:2B:50][0.5:2B:30]}
$pull
$show
calibre: 0.5, bico: [0.5:2B:50], tambor: {[0.5:2B:30]}
$pull
fail: ja existe grafite no bico
$remove
$show
calibre: 0.5, bico: [], tambor: {[0.5:2B:30]}
$end
```


```bash
#__case escrevendo 1
$init 0.9
$insert 0.9 4B 14
$insert 0.9 4B 16
$write
fail: nao existe grafite no bico
$pull
$show
calibre: 0.9, bico: [0.9:4B:14], tambor: {[0.9:4B:16]}
$write
$show
calibre: 0.9, bico: [0.9:4B:10], tambor: {[0.9:4B:16]}
$remove
$pull
$show
calibre: 0.9, bico: [0.9:4B:16], tambor: {}
$write
$show
calibre: 0.9, bico: [0.9:4B:12], tambor: {}
$write
fail: folha incompleta
$show
calibre: 0.9, bico: [0.9:4B:10], tambor: {}
$end
```


## Diagrama

![](diagrama.png)


***
## Esqueleto

<!--FILTER Solver.java java-->
```java
class Lead {
    private float thickness;
    private String hardness;
    private int size;
    public Lead(float thickness, String hardness, int size);
    public String toString();
    public int usagePerSheet();
    public float getThickness();
    public String getHardness();
    public int getSize();
    public void setSize(int size);
}
class Pencil {
    private float thickness;
    private Lead tip; //lead da ponta
    private ArrayList<Lead> barrel; //grafites no cano
    public Pencil(float thickness);
    public String toString();
    //insere um lead no barril
    public boolean insert(Lead lead);
    //remove e retorna o lead da ponta
    public Lead remove();
    // se a ponta estiver vazia, puxa o próximo lead do barril
    public boolean pull();
    //se tiver grafite suficiente no bico, gaste e retorne true
    //lembre que os últimos 10mm não podem ser utilizados
    public void writePage();
}
class Solver{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Pencil lapiseira = new Pencil(0.5f);
        while(true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);
            String ui[] = line.split(" ");
            if(ui[0].equals("end")) {
                break;
            } else if(ui[0].equals("help")) {
                System.out.println("init _calibre; insert _calibre _dureza _tamanho; remove; writePage _folhas");
            } else if(ui[0].equals("init")) { //thickness
                lapiseira = new Pencil(Float.parseFloat(ui[1]));
            } else if(ui[0].equals("insert")) {//thickness hardness size
                float thickness = Float.parseFloat(ui[1]);
                String hardness  = ui[2];
                int size = Integer.parseInt(ui[3]);
                lapiseira.insert(new Lead(thickness, hardness, size));
            } else if(ui[0].equals("remove")) {
                lapiseira.remove();
            } else if(ui[0].equals("show")) {
                System.out.println(lapiseira);
            } else if (ui[0].equals("write")) {
                lapiseira.writePage();
            } else if (ui[0].equals("pull")) {
                lapiseira.pull();
            }  else {
                System.out.println("fail: comando invalido");
            }
        }
        scanner.close();
    }
}
```
<!--FILTER_END-->