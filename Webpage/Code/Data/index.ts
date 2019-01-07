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
    module: () => Promise<any>,
} 

/** All the Data of an Topic, aka a set of algorithms  */
export interface TopicData extends NameLink {
    /** All the algorithms that have the topic */
    Algorithms: AlgorithmData[],

    /** And http link to the directory that holds the algorithms */
    linkToDirectoryCode: string,
}


/** All the differents modifications you can have on the code shown  */
export interface CodeStyles {
    /** the size in REMs */
    fontSize: number,

    /** A name of a Highlightjs theme, @see https://highlightjs.org */
    theme: string,

    /** Elevation */
    elevation?: boolean,
}

/** All the differents actiond you can have on the code shown  */
export interface CodeActions {
}

/** All the differents things you can edit on the code shown  */
export interface CodeConfig {
    CodeStyles: CodeStyles,
    CodeActions: CodeActions
}


/** An array of strings */
type Text = string[]

/** A part of a file with a name */
export interface FilePart        { 
    /** Name of the section */
    name: string, 

    /** [start, end] of the section */
    parts: [number, number] 
}

/** 
 * An object, each key is a file, each 
 * value is an object where each key is
 * a section name and each value is a text 
 * */
export interface FilesDataResult { [index: string]: {[index: string]: Text} }

/** 
 * An object, each key is a file, each 
 * value is an array of FilePart
 * */
export interface FilesData { [index: string]: FilePart[] }


/** 
 * The props that an Algorithm page should have
 * */
export interface AlgorithmPageProps {
    filesData?: FilesDataResult,
}

/** 
 * The information that defines an Algorithm
 * */
export interface AlgorithmPageInformation {
    filesData: FilesData,
    CodeConfig: CodeConfig
}