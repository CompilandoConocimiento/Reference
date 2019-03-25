import React, { FunctionComponent } from "react"
import { Link } from "react-router-dom"
import { toTop } from "../Helpers"
/**
 * The top bar.
 */
const NavigationMenu: FunctionComponent<{ sideMenuID: string }> = props => (
  <div className="navbar-fixed">
    <nav className="blue-grey darken-3">
      <div className="nav-wrapper z-depth-1">
        <div className="container">
          <div className="brand-logo white-text center" style={{ fontSize: "1.2rem" }}>
            <b>Competitive</b> Reference
          </div>

          <a
            data-target={props.sideMenuID}
            className="sidenav-trigger show-on-large"
            style={{ cursor: "pointer" }}
          >
            <i className="material-icons white-text">menu</i>
          </a>

          <Link className="right" to="/" onClick={toTop}>
            <i className="material-icons white-text">home</i>
          </Link>
        </div>
      </div>
    </nav>
  </div>
)

export default NavigationMenu
