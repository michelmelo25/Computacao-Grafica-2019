# Computacao-Grafica-2019

# Trabalho 1

## Parte 1
1. **Implementar um modelador** [**6.0**]
	1. **implementacao orientada a objeto** (definir uma classe Objeto)[**2.5**]
		+ **heranca**[**1.0**]
			+ a ser implementado por classes mais específicas (herdando da classe Objeto)
		+ **transformacoes**[**0.5**]
			+ incluir atributos referentes às possíveis transformações, translação/rotação/escala
		+ **selecao**[**0.5**]
			+ incluir um atributo na classe Objeto para dizer se o objeto está ou não selecionado
				+ se deve ou não ser pintado com uma cor de destaque (branco, por exemplo)
				+ usá-lo como teste no método desenhar
		+ **sistema local de referencia**[**0.5**]
			+ incluir um atributo na classe Objeto para alternar entre desenhar ou não os eixos do sist local do objeto
			+ usá-lo como teste no método desenhar
	2. **manipulacao do vetor de Objetos**[**1.5**]
		+ **permitir incluir objetos nesse vetor** (usando o teclado)[**0.5**]
			+ permitir incluir objetos independentes, inclusive do mesmo tipo (mesma classe filha)
				+ cada tipo de objeto deve ser associado a uma tecla diferente
			+ objetos devem ser incluidos com seu centro coincidindo com a origem do sist local
				+ seu sist local deve estar inicialmente alinhado com o sist global
				+ usar o proprio modelador implementado, durante sua execucao, para posicionar cada objeto (selecionado) no cenario
		+ **permitir alternar/selecionar os objetos desse vetor** (de um a um, seguindo a ordem do vetor)[**0.5**]
			+ marcar o objeto selecionado (pintar com uma cor de destaque, o objeto inteiro com a mesma cor)
			+ definir teclas para avançar e para voltar no vetor
				+ permitir avanco e retorno ciclico (indo do ultimo para o primeiro e vice-versa)
		+ **permitir apagar objetos desse vetor** (usando o teclado)[**0.5**]
			+ permitir apagar o objeto selecionado
			+ permitir apagar o ultimo objeto do vetor

	3. **permitir modificar os atributos do objeto selecionado**[**1.5**]
		+ **translação/rotação/escala** (usando o mouse)[**1.2**]
			+ forçar o usuario a modelar o cenario a partir da execucao do modelador (programa), e nao direto no codigo
		
		+ **desenhar ou não eixos do sist local** (usando alguma tecla)[0.3]
	4. **permitir salvar e carregar todos os objetos (todos os seus atributos) do vetor em/de arquivo**[**0.5**]


2. **Câmeras**
	1. **incluir implementação pronta já disponibilizada nos exemplos** (class Camera [CameraDistante e/ou CameraJogo])[**0.2**]
		+ que permite movimentar a câmera pelo cenário

	2. **pré-estabelecer posições/orientações (pelo menos 3) de câmera específicas interessantes, de acordo com o cenário modelado**[**0.3**]
		+ permitir alternar entre essas posições/orientações pré-estabelecidas usando o teclado


3. **Modelar, salvar e carregar um cenário com um certo nível de detalhes (avaliacao subjetiva considerando complexidade e criatividade)**[**1.0**]
	+ basear-se nos exercícios (no dropbox) ou sugestões dadas (não modelar laboratório, nem sala de aula)
		+ pelo menos 5 objetos diferentes (alguns deles podem usar 3ds)
	+ pelo menos 2 objetos devem ser modelados usando glBegin(...);...glEnd();
		+ definir os glNormal3f(...); das faces (composta pelos vértices) adequadamente
		+ pelo menos 2 faces inclinadas (ou seja, não alinhadas aos eixos do sist de coordenadas local do objeto)
			+ usar transformacoes locais fixas pode facilitar
