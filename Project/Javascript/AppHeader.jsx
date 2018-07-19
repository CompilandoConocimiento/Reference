// =====================================================================
// ============                 IMPORTS            =====================
// =====================================================================
import React from "react"

// =====================================================================
// ============     HEADER COMPONENT       =============================
// =====================================================================
export default class AppHeader extends React.Component {

	constructor(props) {
		super(props)
		this.state = {Languages: this.props.Languages}
	}

	componentDidMount() {
		const Elements = document.querySelectorAll('.sidenav')
		const Sidenavs = M.Sidenav.init(Elements, {draggable: true, edge: "left"})
	}

	render () {

		const ManageChangeLanguage = () => {
			this.props.OnChangeLanguage()

			setTimeout(() => {
				const Element = document.getElementById('SideMenu')
				const Instance = M.Sidenav.getInstance(Element)
				Instance.close()
			}, 500)
		}

		const NavigationMenu = (
			<div className="navbar-fixed">
				<nav className="blue-grey darken-3">
					<div className="nav-wrapper z-depth-1">
						<div className="container">
							<div className="brand-logo white-text center" style={{fontSize: '1.3rem'}}>
								<b>Soy</b>Oscar<b>RH</b>
							</div>
							<a href="" data-target="SideMenu" className="sidenav-trigger show-on-large">
								<i className="material-icons white-text">menu</i>
							</a>
							<a href="#AboutMe" className="right" style={{height: "100%"}}>
								<img 
									style={{width: '2.2rem', verticalAlign: "middle"}} 
									src="Assets/Icons/LogoWhite.png"
								/>
							</a>
						</div>
					</div>
				</nav>
			</div>
		)
		
		const Parts = []
		Object.entries(this.props.Data).forEach( ([Key, Values]) => {
			Parts.push(
				<li key={Key}>
					<a className="subheader">{Values.Title}</a>
				</li>
			)

			Parts.push(
				Values.Links.map( 
					(Link, Index) => (
						<li key={`${Key} ${Index}`}>
							<a className="waves-effect" href={`#${Link[1]}`}>
								{Link[0]}
							</a>
						</li>
					)
				)
			)
		})


		const SideMenu = (
			<ul id="SideMenu" className="sidenav">
				
				<li className="center">
					<br />
					<h5 style={{fontWeight: 500, fontSize: "2.1rem"}}>
						<b>Soy</b>Oscar<b>RH</b>
					</h5>
				</li>
				<br />

				<li>
					<div className="row">
						<div className="col s8 offset-s2">
							<div className="row">
								<a target="_blank" href="https://github.com/SoyOscarRH">
									<img className="col s3" src="Assets/Icons/github.png"/>
								</a>
								<a target="_blank" href="http://compilandoconocimiento.com/">
									<img className="col s3" src="Assets/Icons/wordpress.png"/>
								</a>
								<a target="_blank" href="http://twitter.com/SoyOscarRH">
									<img className="col s3" src="Assets/Icons/twitter.png"/>
								</a>
								<a target="_blank" href="https://telegram.me/SoyOscarRH">
									<img className="col s3" src="Assets/Icons/telegram.png"/>
								</a>
							</div>
						</div>
					</div>
				</li>

				<li>
					<a className="subheader center">Language</a>
				</li>

				<li className="container">
					<div className="switch center">
						<label>
							{this.state.Languages[0]}
							<input type="checkbox" onClick={ManageChangeLanguage} />
							<span className="lever"></span>
							{this.state.Languages[1]}
						</label>
					</div>  
				</li>
				<li><div className="divider" /></li>
				{Parts}
				<br />
				<br />
				<br />
				<br />
				<br />
			</ul>
		)

		return (
			<React.Fragment>
				{NavigationMenu}
				{SideMenu}
			</React.Fragment>
		)
	}
}