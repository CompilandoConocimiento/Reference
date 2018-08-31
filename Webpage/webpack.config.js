module.exports = {
	entry: './Code/GeneralApp/App.tsx',
	output: {
		path: __dirname + '/Distribution',
		publicPath: '/',
		filename: 'bundle.js'
	},
	resolve: {
		extensions: ['.tsx', '.ts', '.jsx', '.js', '.css', ]
	},
	module: {
		rules: [
		  {
			test: /\.(js|jsx|tsx|ts)$/,
			exclude: /node_modules/,
			use: 'babel-loader'
		  },
		  {
		  test: /\.(png|jpg|gif)$/,
			use: [
			  {
				loader: 'file-loader',
				options: {}  
			  }
			]
		  },
		  {
			test: /\.css$/,
			use: [
			  'style-loader',
			  {
				loader: 'typings-for-css-modules-loader?&namedExport&camelCase',
				options: {
				  modules: true,
				  camelCase: true,
				  namedExport: true,
				  localIdentName: "[name]_[local]_[hash:base64]",
				  sourceMap: true,
				  minimize: true
				}
			  }
			]
		  }
		]
	}
};