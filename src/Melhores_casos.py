import pandas as pd
import plotly.express as px
import os
import pandas as pd
import matplotlib.pyplot as plt
import plotly.graph_objects as go
AVL = pd.read_csv('avgCaseAVL.csv')
B1 = pd.read_csv('avgCaseB1.csv')
B5 = pd.read_csv('avgCaseB5.csv')
B10 = pd.read_csv('avgCaseB10.csv')
Rubro = pd.read_csv('avgCaseRubroNegra.csv')
#plt.xscale("log")
#plt.xticks(range(0, 12, 100))
#plt.plot(AVL)
fig1 = px.line(AVL, x="chaves", y="operações", title='Piores casos', log_y=True)
fig1.update_traces(line_color='purple', name='AVL', showlegend=True)

#plt.plot(B1)
fig2 = px.line(B1, x="chaves", y="operações", title='Piores casos', log_y=True)
fig2.update_traces(line_color='red', name='B1', showlegend=True)
#plt.plot(B5)
fig3 = px.line(B5, x="chaves", y="operações", title='Piores casos', log_y=True)
fig3.update_traces(line_color='green', name='B5', showlegend=True)
#plt.plot(B10)
fig4 = px.line(B10, x="chaves", y="operações", title='Piores casos', log_y=True)
fig4.update_traces(line_color='black', name='B10', showlegend=True)
#plt.plot(Rubro)
fig5 = px.line(Rubro, x="chaves", y="operações", title='Piores casos', log_y=True)
fig5.update_traces(line_color='yellow', name='Rubro Negra', showlegend=True)

fig6 = go.Figure(data=fig2.data + fig1.data + fig3.data + fig4.data + fig5.data)
#fig6.yscale("log")

fig6.update_xaxes(title_text="chaves")
fig6.update_yaxes(title_text="operações", type = "log")
fig6.update_layout({
    'plot_bgcolor': 'rgba(100,200,160,190)',
    'paper_bgcolor': 'rgba(100,150,100,100)'
})
#ax = fig6.add_subplot(111)
#ax.set_xscale('log')
fig6.show()

AVL0 = pd.read_csv('worstCaseAVL.csv')
B10 = pd.read_csv('worsCaseB1.csv')
B50 = pd.read_csv('worsCaseB5.csv')
B100 = pd.read_csv('worsCaseB10.csv')
Rubro0 = pd.read_csv('worsCaseRubroNegra.csv')
#plt.xscale("log")
#plt.xticks(range(0, 12, 100))
#plt.plot(AVL)
fig7 = px.line(AVL0, x="chaves", y="operações", title='Piores casos', log_y=True)
fig7.update_traces(line_color='purple', name='AVL', showlegend=True)

#plt.plot(B1)
fig8 = px.line(B10, x="chaves", y="operações", title='Piores casos', log_y=True)
fig8.update_traces(line_color='red', name='B1', showlegend=True)
#plt.plot(B5)
fig9 = px.line(B50, x="chaves", y="operações", title='Piores casos', log_y=True)
fig9.update_traces(line_color='green', name='B5', showlegend=True)
#plt.plot(B10)
fig10 = px.line(B100, x="chaves", y="operações", title='Piores casos', log_y=True)
fig10.update_traces(line_color='black', name='B10', showlegend=True)
#plt.plot(Rubro)
fig11 = px.line(Rubro0, x="chaves", y="operações", title='Piores casos', log_y=True)
fig11.update_traces(line_color='yellow', name='Rubro Negra', showlegend=True)

fig12 = go.Figure(data=fig8.data + fig9.data + fig10.data + fig11.data + fig11.data)
#fig6.yscale("log")

fig12.update_xaxes(title_text="chaves")
fig12.update_yaxes(title_text="operações", type = "log")
fig12.update_layout({
    'plot_bgcolor': 'rgba(100,200,160,190)',
    'paper_bgcolor': 'rgba(100,150,100,100)'
})
#ax = fig6.add_subplot(111)
#ax.set_xscale('log')
fig12.show()