import pandas as pd
import plotly.express as px
import plotly.graph_objects as go

xAxis = "chaves"
yAxis = "operações"
graphTitle = "Caso Médio"

AVL = pd.read_csv('data/avgCaseAVL.csv').sort_values(xAxis)
B1 = pd.read_csv('data/avgCaseB1.csv').sort_values(xAxis)
B5 = pd.read_csv('data/avgCaseB5.csv').sort_values(xAxis)
B10 = pd.read_csv('data/avgCaseB10.csv').sort_values(xAxis)
Rubro = pd.read_csv('data/avgCaseRubroNegra.csv').sort_values(xAxis)

fig1 = px.line(AVL, x = xAxis, y = yAxis, title = graphTitle, log_y=True)
fig1.update_traces(line_color='purple', name='AVL', showlegend=True)

fig2 = px.line(B1, x = xAxis, y = yAxis, title = graphTitle, log_y=True)
fig2.update_traces(line_color='red', name='B1', showlegend=True)

fig3 = px.line(B5, x = xAxis, y = yAxis, title = graphTitle, log_y=True)
fig3.update_traces(line_color='green', name='B5', showlegend=True)

fig4 = px.line(B10, x = xAxis, y = yAxis, title = graphTitle, log_y=True)
fig4.update_traces(line_color='black', name='B10', showlegend=True)

fig5 = px.line(Rubro, x = xAxis, y = yAxis, title = graphTitle, log_y=True)
fig5.update_traces(line_color='yellow', name='Rubro Negra', showlegend=True)

allFig = go.Figure(data=fig2.data + fig1.data + fig3.data + fig4.data + fig5.data)

allFig.update_xaxes(title_text = xAxis)
allFig.update_yaxes(title_text = yAxis)
allFig.update_layout({
    'plot_bgcolor': 'rgba(255, 255, 255, 255)',
    'paper_bgcolor': 'rgba(255,255,255,255)'
})

allFig.show()
