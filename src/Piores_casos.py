import pandas as pd
import plotly.express as px
import os
import pandas as pd
import plotly.graph_objects as go
AVL0 = pd.read_csv('data/worstCaseAVL.csv')
AVL1 = pd.read_csv('data/avgCaseAVL.csv')
B10 = pd.read_csv('data/worstCaseB1.csv')
B50 = pd.read_csv('data/worstCaseB5.csv')
B100 = pd.read_csv('data/worstCaseB10.csv')
Rubro0 = pd.read_csv('data/worstCaseRubroNegra.csv')
#plt.xscale("log")
#plt.xticks(range(0, 12, 100))
#plt.plot(AVL)
fig7 = px.line(AVL0, x="chaves", y="operações", title='Piores casos')
fig7.update_traces(line_color='purple', name='AVL', showlegend=True)

#plt.plot(B1)
fig8 = px.line(B10, x="chaves", y="operações", title='Piores casos')
fig8.update_traces(line_color='red', name='B1', showlegend=True)
#plt.plot(B5)
fig9 = px.line(B50, x="chaves", y="operações", title='Piores casos')
fig9.update_traces(line_color='green', name='B5', showlegend=True)
#plt.plot(B10)
fig10 = px.line(B100, x="chaves", y="operações", title='Piores casos')
fig10.update_traces(line_color='black', name='B10', showlegend=True)
#plt.plot(Rubro)
fig11 = px.line(Rubro0, x="chaves", y="operações", title='Piores casos')
fig11.update_traces(line_color='yellow', name='Rubro Negra', showlegend=True)

fig13 = px.line(AVL1, x="chaves", y="operações", title='Caso médio')
fig13.update_traces(line_color='black', name='AVL', showlegend=True)

fig12 = go.Figure(data=fig7.data + fig13.data)
#fig6.yscale("log")

fig12.update_xaxes(title_text="Chaves")
fig12.update_yaxes(title_text="Operações")
fig12.update_layout({
    'plot_bgcolor': 'rgba(100,200,160,190)',
    'paper_bgcolor': 'rgba(100,150,100,100)'
})
#ax = fig6.add_subplot(111)
#ax.set_xscale('log')
fig12.show()