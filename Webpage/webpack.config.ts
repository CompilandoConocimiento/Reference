import { Configuration } from "webpack"

const Configuration: Configuration = {
  entry: "./Code/App/App",
  output: {
    path: __dirname + "/Distribution/",
    publicPath: "Webpage/Distribution/",
    filename: "[name].bundle.js",
  },
  resolve: {
    extensions: [".tsx", ".ts", ".jsx", ".js", ".css"],
  },
  module: {
    rules: [
      {
        test: /\.(js|jsx|tsx|ts)$/,
        exclude: /node_modules/,
        use: "babel-loader",
      },
      {
        test: /\.css$/,
        use: [
          { loader: 'style-loader' },
          {
            loader: "dts-css-modules-loader",
            options: {
              namedExport: true,
            },
          },
          {
            loader: "css-loader",
            options: {
              camelCase: true,
              localIdentName: "[name]_[local]_[hash:base64]",
              sourceMap: true,
              modules: true,
            },
          },
        ],
      },
    ],
  },
}

module.exports = Configuration
