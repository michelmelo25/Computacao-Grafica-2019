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
	2. manipulacao do vetor de Objetos[**1.5**]
		+ permitir incluir objetos nesse vetor (usando o teclado)[**0.5**]
			+ permitir incluir objetos independentes, inclusive do mesmo tipo (mesma classe filha)
				+ cada tipo de objeto deve ser associado a uma tecla diferente
			+ objetos devem ser incluidos com seu centro coincidindo com a origem do sist local
				+ seu sist local deve estar inicialmente alinhado com o sist global
				+ usar o proprio modelador implementado, durante sua execucao, para posicionar cada objeto (selecionado) no cenario
		+ permitir alternar/selecionar os objetos desse vetor (de um a um, seguindo a ordem do vetor)[**0.5**]
			+ marcar o objeto selecionado (pintar com uma cor de destaque, o objeto inteiro com a mesma cor)
			+ definir teclas para avançar e para voltar no vetor
				+ permitir avanco e retorno ciclico (indo do ultimo para o primeiro e vice-versa)
		+ permitir apagar objetos desse vetor (usando o teclado)[**0.5**]
			+ permitir apagar o objeto selecionado
			+ permitir apagar o ultimo objeto do vetor
