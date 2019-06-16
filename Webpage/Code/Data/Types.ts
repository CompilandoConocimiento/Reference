/** A set of a name and a link  */
export interface NameLink { 
  /** The name of a thing */
  name: string,
  /** The link name to this thing in ReactRouter*/
  link: string
}

/** All the Data of an Algorithm  */
export interface AlgorithmData extends NameLink {
  /** a function that return the module loaded */
  module: () => React.LazyExoticComponent<React.ComponentType<any>>
} 

/** All the Data of an Topic, aka a set of algorithms  */
export interface TopicData extends NameLink {
  /** All the algorithms that have the topic */
  Algorithms: AlgorithmData[],

  /** And http link to the directory that holds the algorithms */
  linkToDirectoryCode: string,
}