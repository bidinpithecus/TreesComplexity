# Trees Complexity

Este trabalho serve para avaliar a complexidade algorítmica de balanceamento de diferentes tipos de árvores.

## Dependencies

[Gcc](https://gcc.gnu.org/) para compilação, visto que foi desenvolvido na linguagem C;

[Python](https://www.python.org/downloads/) para geração dos gráficos. Além do python, são necessários alguns pacotes para a geração dos gráficos. Recomenda-se fazer a instalação destes, com o gerenciador de pacotes do python, [pip](https://pypi.org/project/pip/).

São estes: 

[Pandas](https://pandas.pydata.org/), pode ser instalado executando no prompt `pip install pandas`

[Plotly](https://plotly.com/python/), pode ser instalado executando no prompt `pip install plotly`
 
[Makefile](https://www.gnu.org/software/make/) para execução dos comandos como parte da geração dos gráficos;

## Execução
Para a execução, com ajuda do Makefile, rodando na pasta raíz do projeto o comando `make`, o código será executado, gerado os arquivos de dados csv, localizados no diretório `data/`, e duas abas no navegador serão abertas, através do `localhost`, cada uma delas contendo os 5 gráficos tanto do Caso médio quanto do Pior caso.