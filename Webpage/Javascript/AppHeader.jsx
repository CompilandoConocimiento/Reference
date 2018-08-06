// =====================================================================
// ============                 IMPORTS            =====================
// =====================================================================
import React from "react"
import Topics from './Data'
import { Link } from 'react-router-dom'



// =====================================================================
// ============     HEADER COMPONENT       =============================
// =====================================================================
function NavBar (props) {
    return (
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
}

export default class AppHeader extends React.Component {

    constructor(props) {super(props)}

    componentDidMount() {
        const Elements = document.querySelectorAll('.sidenav')
        M.Sidenav.init(Elements, {draggable: true, edge: "left"})
    }

    render () {
        const CloseSideMenu = () => {
            setTimeout(
                () => {
                    M.Sidenav.getInstance( document.getElementById("SideMenu") ).close()
                    scroll(0,0)
                }
                , 350
            )
        }

        return (
            <header>
                
                <NavBar />

                <ul id="SideMenu" className="sidenav">
                    <li>
                        <br />
                        <h5 className="blue-grey-text text-darken-3" style={{fontWeight: 500, fontSize: "2.1rem"}}>
                            &nbsp;&nbsp;&nbsp;&nbsp; <b>Topics</b>
                        </h5>
                    </li>
                    <br />

                    {Topics.map(
                        (Topic, IndexTopic) => {
                            return (
                                <React.Fragment key={`Render ${IndexTopic}`}>
                                    <li key={`Divider ${IndexTopic}`}><div className="divider" /></li>
                                    <li key={Topic.Link}>
                                        <Link className="waves-effect" onClick={CloseSideMenu} style={{fontSize: "1.1rem"}} to={`/Topic/${Topic.Link}/`}>
                                            {Topic.Name}
                                        </Link>
                                    </li>
                                    {Topic.SubTopics.map( (SubTopic, IndexSubTopic) => (
                                        <li key={`${Topic.Link} ${IndexTopic} ${IndexSubTopic}`}>
                                            <Link className="waves-effect" onClick={CloseSideMenu} to={`/Topic/${Topic.Link}/${SubTopic.Link}`}>
                                                &nbsp;{SubTopic.Name}
                                            </Link>
                                        </li>
                                    ))}
                                </React.Fragment>
                            )
                        }
                    )}
                    
                    <br /><br /><br /><br /><br />
                </ul>

            </header>
        )
    }
}