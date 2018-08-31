import React from "react"
import Topics from '../Data'
import { Link } from 'react-router-dom'

import M from "materialize-css"

const NavBar: React.StatelessComponent<{}> = () => {
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

export default class AppHeader extends React.Component<{}, {}> {

  componentDidMount() {
    const Elements = document.querySelectorAll('.sidenav')
    M.Sidenav.init(Elements, {draggable: true, edge: "left"})
  }

  render () {
    
    function CloseSideMenu () {
      setTimeout(
        () => {
          M.Sidenav.getInstance( document.getElementById("SideMenu") ).close()
          scroll(0, 0)
        }
        , 350
      )
    }

    const TopicsLink: Array<JSX.Element> = Topics.map( (Topic, indexTopic) =>
      <React.Fragment key={`Render ${indexTopic}`}>

        <li key={`Divider ${indexTopic}`}>
          <div className="divider" />
        </li>

        <li key={Topic.link}>
          <Link className="waves-effect" onClick={CloseSideMenu} to={`/Topic/${Topic.link}/`}>
            <span style={{fontSize: "1.1rem"}}>{Topic.name}</span>
          </Link>
        </li>

        {
          Topic.subTopics.map( (SubTopic, indexSubTopic) => 
            <li key={`${Topic.link} ${indexTopic} ${indexSubTopic}`}>
              <Link className="waves-effect" onClick={CloseSideMenu} to={`/Topic/${Topic.link}/${SubTopic.link}`}>
                &nbsp;{SubTopic.name}
              </Link>
            </li>
          )
        }
        
      </React.Fragment>
    )

    return (
      <header>
        
        <NavBar />

        <ul id="SideMenu" className="sidenav">
          
          <li>
            <br />
            <h5 className="blue-grey-text text-darken-3">
              <span style={{fontWeight: 500, fontSize: "2.1rem"}}>
                &nbsp;&nbsp;&nbsp;&nbsp; <b>Topics</b>
              </span>
            </h5>
          </li>
          
          <br />

          {TopicsLink}
          
          <br /><br />
          <br /><br />

        </ul>

      </header>
    )
  }
}