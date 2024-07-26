import streamlit as st
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

df = pd.read_csv("build/2d_heat_equation.csv", sep=" ", header=None)

st.title("Visualization")
st.header("Heatmap")
st.write("Visualization of the results as a heatmap. Red color represents larger values.")

fig, ax = plt.subplots()
sns.heatmap(df.to_numpy(), annot=False, ax=ax, cmap="Reds")
st.pyplot(fig)

st.header("Source data")
st.write("Raw data in a tabular format.")
st.dataframe(df)