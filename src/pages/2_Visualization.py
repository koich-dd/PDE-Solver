import streamlit as st
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Load results from csv data
df = pd.read_csv("build/2d_heat_equation.csv", sep=" ", header=None)

# Set title, header and description
st.title("Visualization")
st.header("Heatmap")
st.write("Visualization of the results as a heatmap. Red color represents larger values.")

# Visualize the results as a heatmap
fig, ax = plt.subplots()
sns.heatmap(df.to_numpy(), annot=False, ax=ax, cmap="Reds")
st.pyplot(fig)

# Show the raw data as a table
st.header("Source data")
st.write("Raw data in a tabular format.")
st.dataframe(df)