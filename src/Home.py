import streamlit as st
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Set titile, header and description on the homepage.
st.title("PDE Solver")
st.header("How to use")
st.write("1. Go to [SolvePDE] page to set configurations and run PDE solver.")
st.write("2. Go to [Visualization] page to see the result visualized as a heatmap.")
st.write("Below is an example of the result in heatmap.")

# Load csv data in sample directory and visualize it as a heatmap.
df = pd.read_csv("sample/2d_heat_equation.csv", sep=" ", header=None)
fig, ax = plt.subplots()
sns.heatmap(df.to_numpy(), annot=False, ax=ax, cmap="Reds")
st.pyplot(fig)