// ======================================================================
// ============          WEB APP IN REACT           =====================
// ======================================================================

/* ========= BASIC REACT THINGS ===============*/
import React from "react"
import ReactDOM from "react-dom"

/* ========= MATERIALIZCE CSS =================*/
import M from "materialize-css"
import "materialize-css/dist/css/materialize.min.css"

/* ========= THE COMPONENTS ==================*/
import {Data} from "./Data"
import AppHeader from "./AppHeader"
import Footer from "./Footer"


// =====================================================================
// ============              APP COMPONENTS        =====================
// =====================================================================
class App extends React.Component {

	constructor(props) {
		super(props)
		const Languages = ["Spanish", "English"]
		
		this.state = {
			Language: Languages[Math.floor(Math.random() * Languages.length)],
		}
	}

	OnChangeLanguage () {
		this.setState((preState) => {
			const NewLanguage = (preState.Language === "English")?
			"Spanish" : "English"

			return {Language: NewLanguage}
		})
	}

	componentDidMount() {
		window.ChangeMessage = () => {
			M.Toast.dismissAll()
			this.OnChangeLanguage() 
		}

		const Message = this.state.Language == "English"? "¿Cambiar idioma?" : "Change language?"
		const ChangeItem = `<button class="btn-flat toast-action" onClick=window.ChangeMessage()>${Message}</button>`
		M.toast({
			html: ChangeItem,
			displayLength: 8000,
		})
	}

	render () {

		const Language = this.state.Language
		const NewLanguage = (Language === "English")? "Spanish" : "English"

		return (
			<React.Fragment>
				
				<header>
						<AppHeader
							Languages        = {[Language, NewLanguage]}
							OnChangeLanguage = {() => this.OnChangeLanguage()}
							Data             = {Data.SideMenu[this.state.Language]} 
						/>
				</header>

				<main>
					<br />

				</main>

				<footer>
					<Footer />
				</footer>

			</React.Fragment>
		)
	}
}

ReactDOM.render(<App />, document.getElementById("ReactApp"))