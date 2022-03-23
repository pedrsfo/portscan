// Nome: Portscan - Scanner de portas

// Autor: Pedro Otávio
// Email: pedr_ofs@hotmail.com
// Atualizado: 23/03/2022

// Este programa tem por finalidade realizar a varredura de portas de um determinado host e descobrir quais
// estão abertas.

#include <stdio.h>	// Biblioteca padrão de entrada e saída de dados.
#include <sys/socket.h> // Biblioteca utilizada para criar sockets.
#include <netdb.h>	// Biblioteca utilizada para conversão de enderços IPs.

// Função principal.
int main (int argc, char *argv[]){

	// Verifica se o usuário entrou com o número de argumentos corretos.
	if (argc < 2) { printf("Modo de uso: %s host\nExemplo: %s 192.168.0.1", argv[0], argv[0]); return(0);}

	int scansocket;	// Inicialização da variável inteira scansocket.
	int conector;	// Inicialização da variável inteira conector.

	struct sockaddr_in alvo; // Inicialização da estrutura do socket alvo.

	// Laço de repetição utilizado para varrer as portas entre 1 e 65535.
	for (int porta = 1; porta < 65535 ; porta++){

// A função socket opera 3 argumentos: Dominio (familia de protocolos), Tipo do protocolo e Número do Protocolo.
		scansocket = socket(AF_INET, SOCK_STREAM, 0);	// Atribuição da função socket à variável scansocket.
		alvo.sin_family = AF_INET;	// Definição do membro da estrutura sin_family que contém AF_INET.
		alvo.sin_port = htons(porta);	// Definição do membro da estrutura sin_port que contém a porta convertida pela função htons.
		alvo.sin_addr.s_addr = inet_addr(argv[1]);	// Definição do membro da estrutura sin)addr.s_addr que contém o endereço IP convertido pela função inet_addr e passado via argumento.

		// Atribuição da função connect à variável conector.
		// A função connect opera opera com 3 argumentos: a váriavel que recebe o socket, a estrutura do socket e o tamanho do socket.
		conector = connect(scansocket, (struct sockaddr *)&alvo, sizeof alvo);

		// Verifica se o retorno da conexão teve sucesso, se houver sucesso:
		if (conector == 0){

			// Imprime na tela a porta em questão que está aberta.
			printf("Porta %d aberta\n", porta);
			close(scansocket);	// Fecha o socket.
			close(conector);	// Fecha a conexão.
		}

		// Se não houver sucesso:
		else{
			close(scansocket);	// Fecha o socket.
			close(conector);	// Fecha a conexão.
		}
	}

return(0);	// Execução com sucesso.
}
