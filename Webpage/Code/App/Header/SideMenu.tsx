import React, { FunctionComponent, useContext, Fragment } from "react"
import { Link } from "react-router-dom"

import { IndexDataContext } from "../App"

/**
 * We use the TopicsData to generate a side menu index, it renders an array of <li>
 * that that have the topic name, divider and links to algorithms.
 *
 * @param sideMenuID ID dom node of the sideMenu
 * @param onClose  A callback to call when user clicks (that should close the side menu)
 */
const SideMenu: FunctionComponent<{ sideMenuID: string; onClose: () => void }> = props => {
  const IndexData = useContext(IndexDataContext)
  return (
    <ul id={props.sideMenuID} className="sidenav">
      <li>
        <h5 className="blue-grey-text text-darken-3" style={{ margin: "32px" }}>
          <span style={{ fontWeight: 500, fontSize: "2.1rem" }}>
            <b>Topics</b>
          </span>
        </h5>
      </li>

      {IndexData.map(Topic => {
        const baseLink = `/Topic/${Topic.link}/`
        return (
          <Fragment key={Topic.name}>
            <li>
              <div className="divider" />
            </li>

            <LinkToTopic name={Topic.name} link={baseLink} size="1.1rem" onClick={props.onClose} />

            {Topic.Algorithms.map(algorithm => (
              <LinkToTopic
                key={algorithm.name}
                name={`\u00A0\u00A0 ${algorithm.name}`}
                link={baseLink + algorithm.link}
                onClick={props.onClose}
                size="0.95rem"
              />
            ))}
          </Fragment>
        )
      })}
    </ul>
  )
}

/**
 * A react router link that send you to a topic.
 *
 * @param link The link to the topic
 * @param size The size of the link using CSS fontSize, (ei "1.15rem")
 * @param onClick A callback to call when user clicks
 */
const LinkToTopic: FunctionComponent<{
  link: string
  size: string
  name: string
  onClick: () => void
}> = props => (
  <li>
    <Link className="waves-effect" onClick={props.onClick} to={props.link}>
      <span style={{ fontSize: props.size }}>{props.name}</span>
    </Link>
  </li>
)

export default SideMenu
