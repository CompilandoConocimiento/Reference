// =====================================================================
// ============                 IMPORTS            =====================
// =====================================================================
import React from "react"
import { Link } from 'react-router-dom'


// =====================================================================
// ============     HEADER COMPONENT       =============================
// =====================================================================
export default class AppHeader extends React.Component {

	constructor(props) {
		super(props)
	}

	componentDidMount() {
		const Elements = document.querySelectorAll('.sidenav')
		const Sidenavs = M.Sidenav.init(Elements, {draggable: true, edge: "left"})
	}

	render () {

		const NavigationMenu = (
			<div className="navbar-fixed">
				<nav className="blue-grey darken-3">
					<div className="nav-wrapper z-depth-1">
						<div className="container">
							<div className="brand-logo white-text center" style={{fontSize: '1.3rem'}}>
								<b>Competitive</b> Reference
							</div>
							<a href="" data-target="SideMenu" className="sidenav-trigger show-on-large">
								<i className="material-icons white-text">menu</i>
							</a>
							<Link className="right" to="/">
								<i className="material-icons white-text">home</i>
							</Link>
						</div>
					</div>
				</nav>
			</div>
		)
		
		const TopicsLinks = this.props.Data.map(
			(Topic, IndexTopic) => {
				const SubTopics = Topic[1].map(
					(SubTopic, IndexSubTopic) => (
						<li key={`${Topic[0][0]} ${IndexTopic} ${IndexSubTopic}`}>
							<Link className="waves-effect" to={`/Topic/${Topic[0][1]}/${SubTopic[1]}`}>
								&nbsp;{SubTopic[0]}
							</Link>
						</li>
					)
				)

				return (
					<React.Fragment key={`Render ${IndexTopic}`}>
						<li key={`Divider ${IndexTopic}`}>
							<div className="divider" />
						</li>
						<li key={Topic[0][0]}>
							<a className="subheader">{Topic[0][0]}</a>
						</li>
						{SubTopics}
					</React.Fragment>
				)

			}
		)

		const SideMenu = (
			<ul id="SideMenu" className="sidenav">
				
				<li>
					<br />
					<h5 style={{fontWeight: 500, fontSize: "2.1rem"}}>
						&nbsp;&nbsp;&nbsp;&nbsp;
						<b>Topics</b>
					</h5>
				</li>
				<br />
				{TopicsLinks}
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